n, m, k = input().split()
k = int(k[2:])
n = int(n)
m = int(m)

ans = {}
for i in range(n):
    s, n = input().split()
    n = int(n) * k // 100
    if n < 100:
        continue
    ans[s] = n

for i in range(m):
    s = input()
    if not s in ans:
        ans[s] = 0

print(len(ans))
for k, v in sorted(ans.items()):
    print(k, v)