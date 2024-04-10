n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = 1
cur = 1
for i in range(n - 1):
    if(a[i] != a[i + 1]):
        cur += 1
    else:
        cur = 1
    ans = max(ans, cur)

print(ans)