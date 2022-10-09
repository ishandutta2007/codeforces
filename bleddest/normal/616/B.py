n, m = map(int, input().split())

a = [[] for i in range(n)]
for i in range(n):
    a[i] = list(map(int, input().split()))

b = map(min, a)
ans = max(b)

print(ans)