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

n = int(input())
l = list(map(int, input().split()))

stMax = SegmentTree(l)
stMin = SegmentTree(l, default = 10**10,func=min)

nexSmol = [-1] * n
nexTol = [-1] * n

smolS = [n-1]
tolS = [n-1]

for i in range(n - 2, -1 ,-1):
    while smolS and l[smolS[-1]] >= l[i]:
        smolS.pop()
    if smolS:
        nexSmol[i] = smolS[-1]
    smolS.append(i)

    while tolS and l[tolS[-1]] <= l[i]:
        tolS.pop()
    if tolS:
        nexTol[i] = tolS[-1]
    tolS.append(i)

best = [n] * n
best[0] = 0

for i in range(n - 1):
    curr = best[i]

    if l[i + 1] > l[i]:
        reach = i + 1
        best[i+1] = min(curr + 1, best[i+1])
        while nexSmol[reach] != -1:
            reach = nexSmol[reach]
            if stMin.query(i+1,reach) < l[i]:
                break
            best[reach] = min(curr + 1, best[reach])
        
    elif l[i + 1] < l[i]:
        reach = i + 1
        best[i+1] = min(curr + 1, best[i+1])
        while nexTol[reach] != -1:
            reach = nexTol[reach]
            if stMax.query(i+1,reach) > l[i]:
                break
            best[reach] = min(curr + 1, best[reach])
            
    else:
        best[i+1] = min(curr + 1, best[i+1])
print(best[-1])