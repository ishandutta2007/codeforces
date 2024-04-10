import sys
input = sys.stdin.readline

class SegmentTree:
    def __init__(self, data, default=0, func=lambda x, y: x + y):
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

    def clear(self, i):
        if i >= self._size:
            self.data[i] = 0

        if self.data[i]:
            self.data[i] = 0
            self.clear(i + i)
            self.clear(i + i + 1)

SZ = 200005

ST = SegmentTree([0] * (2 * SZ))

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    p = [0] * n
    for i in range(n):
        p[l[i] - 1] = i
    res = 0

    for i in range(n - 1):
        l = p[i]
        r = p[i + 1]
        
        if r < l:
            r += SZ

        seen = ST.query(l, r)
        tot = (p[i + 1] - p[i] - 1) % n

        res += (i + 1) * (tot - seen)
        #print(tot, seen)
            
        ST[p[i]] = 1
        ST[p[i] + SZ] = 1

    out.append(res)
    ST.clear(1)
    #print(ST)
        

print('\n'.join(map(str, out)))