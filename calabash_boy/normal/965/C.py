n, k, M, D = map(int, input().split())

ans = 0
for d in range(1, D + 1):
    # (d - 1) * k * x + x <= n
    maxx = M
    maxx = min(n // ((d - 1) * k + 1), maxx)
    
    if maxx == 0:
        continue
    reald = (n // maxx + k - 1) // k
    if reald != d:
        continue
    
    def f(x):
        return x * (d - 1) + x
    
    ans = max(ans, f(maxx))
print(ans)