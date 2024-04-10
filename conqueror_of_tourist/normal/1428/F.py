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
s = input()

pref = []
curr = 0
for c in s:
    if c == '1':
        curr += 1
    else:
        curr = 0
    pref.append(curr)

suff = []
curr = 0
for c in s[::-1]:
    if c == '1':
        curr += 1
    else:
        curr = 0
    suff.append(curr)
suff.reverse()
    

st = SegmentTree(suff)

out = 0
add = 0
for i in range(n):
    if s[i] == '1':
        lo = -1
        hi =  i - pref[i] + 1
        while hi - lo > 1:
            t = (lo + hi) // 2
            if st.query(t, i - pref[i] + 1) >= pref[i]:
                lo = t
            else:
                hi = t
        add += (i - lo)
    #print(add)
    out += add
print(out)