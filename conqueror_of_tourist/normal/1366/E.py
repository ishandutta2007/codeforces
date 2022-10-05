n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

MOD = 998244353

out = 1

first = -1
curr = m - 1

for i in range(n - 1, -1 ,-1):
    while a[i] < b[curr]:
        if first > -1:
            out *= (first - i)
            out %= MOD
        else:
            out = 0
        first = -1
        curr -= 1
        
        if curr < 0:
            out = 0
            break
    if a[i] == b[curr] and first == -1:
        first = i

if curr == 0 and first != -1:
    print(out)
else:
    print(0)