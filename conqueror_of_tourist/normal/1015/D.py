n, k, s = map(int,input().split())
s -= k
if s < 0:
    s = 10 ** 100
out = []
curr = 1
for i in range(k):
    nex = min(s, n - 2)
    if i % 2:
        curr -= nex + 1
    else:
        curr += nex + 1
    s -= nex
    out.append(curr)
if s == 0:
    print('YES')
    print(*out)
else:
    print('NO')