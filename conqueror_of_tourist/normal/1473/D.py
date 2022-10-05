def comb(x, y):
    low = min(x[0], y[0] + x[2])
    high = max(x[1], y[1] + x[2])
    tot = y[2] + x[2]
    return (low, high, tot)

class SegmentTree:
    def __init__(self, data, default=(0,0,0), func=comb):
        """initialize the segment tree with data"""
        self._default = default
        self._func = func
        self._len = len(data)
        self._size = _size = 1 << (self._len - 1).bit_length()

        self.data = [default] * (2 * _size)
        self.data[_size:_size + self._len] = data
        for i in reversed(range(_size)):
            self.data[i] = func(self.data[i + i], self.data[i + i + 1])

    def __delitem__(self, idx):
        self[idx] = self._default

    def __getitem__(self, idx):
        return self.data[idx + self._size]

    def __setitem__(self, idx, value):
        idx += self._size
        self.data[idx] = value
        idx >>= 1
        while idx:
            self.data[idx] = self._func(self.data[2 * idx], self.data[2 * idx + 1])
            idx >>= 1

    def __len__(self):
        return self._len

    def query(self, start, stop):
        """func of data[start, stop)"""
        start += self._size
        stop += self._size

        res_left = res_right = self._default
        while start < stop:
            if start & 1:
                res_left = self._func(res_left, self.data[start])
                start += 1
            if stop & 1:
                stop -= 1
                res_right = self._func(self.data[stop], res_right)
            start >>= 1
            stop >>= 1

        return self._func(res_left, res_right)

    def __repr__(self):
        return "SegmentTree({0})".format(self.data)

import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n, m = map(int, input().split())
    data = [(0,0,0)] * (n + 5)
    s = input().strip()
    for i in range(n):
        data[i] = (0,1,1) if s[i] == '+' else (-1,0,-1)

    seg = SegmentTree(data)
        
    for q in range(m):
        l, r = map(int, input().split())
        left = seg.query(0, l - 1)
        right = seg.query(r, n + 2)

        tot = comb(left, right)
        out.append(1 + tot[1] - tot[0])
print('\n'.join(map(str,out)))