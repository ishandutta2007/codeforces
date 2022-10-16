t = int(input())
for _ in range(t):
    n, m, k = map(int, input().split())
    print('YES' if n * m - 1 == k else 'NO')