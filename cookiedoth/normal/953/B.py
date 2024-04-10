def gcd(a, b):
    a = abs(a)
    b = abs(b)
    while (b != 0):
        a %= b
        a, b = b, a
    return a

n = int(input())
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in range(n - 1):
    ans = gcd(ans, a[i + 1] - a[i])
print((a[-1] - a[0]) // ans + 1 - n)