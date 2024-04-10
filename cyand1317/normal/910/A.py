n, d = map(int, input().split())
s = input()

a = [(n + 1)] * n

a[0] = 0
for i in range(1, n):
    if s[i] == '1':
        for j in range(max(0, i - d), i):
            a[i] = min(a[i], a[j] + 1)

print(a[n - 1] if a[n - 1] < n else -1)