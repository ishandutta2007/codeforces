n = int(input())

s = input()

dt = [n + 10] * n

for i in range(n):
    if i > 0 and s[i] != "0":
        dt[i] = max([i, n - i])

mn = min(dt)

ans = int(s)

for i in range(n):
    if dt[i] == mn:
        ans = min([ans, int(s[:i]) + int(s[i:])])

print(ans)