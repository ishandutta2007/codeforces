n, k = map(int, input().split())
l = list(map(int, input().split()))
t = list(map(int, input().split()))
base = 0
for i in range(n):
    base += l[i]*t[i]
    if t[i]:
        l[i] = 0
curr = sum(l[:k])
best = curr
for i in range(k, n):
    curr += l[i]
    curr -= l[i - k]
    best = max(best, curr)
print(best + base)