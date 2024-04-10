n = int(input())
a = list(sorted(map(int, input().split())))
ans = 0
for i in range(n):
    ok = False
    for f in range(i):
        if a[i] % a[f] != 0: 
            continue
        ok = True
        break
    ans += int(not ok)
print(ans)