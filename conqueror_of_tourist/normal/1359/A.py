t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    most = min(m, n//k)
    m -= most
    rest = (m + k - 2)//(k - 1)
    print(most-rest)