n, m, k = map(int, raw_input().split(' '))

a = []
for i in xrange(m + 1):
    a.append(int(raw_input()))
    
ans = 0
for i in xrange(0, m):
    if bin(a[i] ^ a[m]).count('1') <= k:
        ans += 1

print ans