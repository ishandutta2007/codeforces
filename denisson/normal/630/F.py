n = int(input())
aa = n * (n - 1) * (n - 2) * (n - 3) * (n - 4)
ans = 0
ans += aa // 120
aa *= n - 5
ans += aa // 720
aa *= n - 6
ans += aa // 720 // 7
print(ans)