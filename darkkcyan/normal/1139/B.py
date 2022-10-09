n = int(input())
a = list(int(x) for x in input().split())
 
ans = a[-1]
cur = a[-1]
for i in reversed(a[:-1]):
    cur = min(cur - 1, i)
    if cur <= 0:
        break
    ans += cur
print(ans)