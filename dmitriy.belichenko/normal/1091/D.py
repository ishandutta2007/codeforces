n = int(input())
x = n
for p in range(1, n):
    x = (p + 1) * (x - 1) % 998244353
print(x)