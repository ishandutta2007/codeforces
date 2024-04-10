class SegmentTree:
    def __init__(self, data, default=0, func=max):
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

import sys, random
input = sys.stdin.readline
out = []
t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))

    pr = []
    m = n
    for i in range(2, 10 ** 3):
        if m % i == 0:
           pr.append(i)

           while m % i == 0:
               m //= i
    if m > 1:
        pr.append(m)

    sz = len(pr)

    '''for i in range(sz):
        if pr[i] == n:
            pr[i] = 1'''


    segs = []
    vals = []
    for p in pr:
        m = n // p
        l = [0] * m
        for i in range(n):
            l[i % m] += a[i]
        segs.append(SegmentTree(l))
        vals.append(n//p * segs[-1].data[1])
        
    out.append(max(vals))
    for _ in range(q):
        p, x = map(int, input().split()); p -= 1
        diff = x - a[p]
        a[p] = x
        for i in range(sz):
            pp = pr[i]
            m = n // pp
            segs[i][p % m] += diff
            vals[i] = (n//pp * segs[i].data[1])
        out.append(max(vals))
    
print('\n'.join(map(str, out)))