n = input()
ans = 0

a = 0
b = 1

while b <= n:
    a, b = b, a + b
    ans += 1

print ans - 2