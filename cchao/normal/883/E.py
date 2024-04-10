n = input()
s = raw_input()
m = input()

v = set(s)

import string
ans = 0
for c in string.lowercase:
    if c not in v:
        ans |= 1 << (ord(c) - ord('a'))

for it in xrange(m):
    t = raw_input()
    msk = 0
    f = False
    for i in xrange(n):
        if s[i] == '*':
            if t[i] in v:
                msk = ans
                break
            msk |= 1 << (ord(t[i]) - ord('a'))
        elif s[i] != t[i]:
            msk = ans
            break
    ans &= msk

print bin(ans).count('1')