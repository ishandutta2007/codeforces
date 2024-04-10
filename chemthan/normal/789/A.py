n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
ans = 0
for i in range(0, n):
    ans += (a[i] + k - 1) // k
print((ans + 1) // 2)