t = int(input())

for _ in range(t):
    r, b, d = map(int, input().split())
    x = min(r, b) * d
    print('YES' if abs(r - b) <= x else 'NO')