n, k = map(int, input().split())
print(k * (6 * (n - 1) + 5))
for i in range(0, n):
    t = [6 * i + 1, 6 * i + 2, 6 * i + 3, 6 * i + 5]
    print(' '.join(map(lambda m: str(m * k), t)));