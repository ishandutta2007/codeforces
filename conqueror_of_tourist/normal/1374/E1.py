n, k = map(int, input().split())
both = []
a = []
b = []
for _ in range(n):
    t, ai, bi = map(int, input().split())
    if ai == 1 and bi == 1:
        both.append(t)
    elif ai == 1:
        a.append(t)
    elif bi == 1:
        b.append(t)

both.sort()
a.sort()
b.sort()

for l in [both,a,b]:
    if len(l) < k:
        l += [10 ** 10] * (k - len(l))

if len(a) > k:
    a = a[:k]
if len(b) > k:
    b = b[:k]
if len(both) > k:
    both = both[:k]

out = 0
for i in range(k):
    out += min(a[i] + b[i],both[-i-1])

if out >= 10 ** 10:
    print(-1)
else:
    print(out)