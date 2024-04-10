n, m = map(int, input().split())

fact = [1]

for i in range(1, n + 1):
    fact.append((fact[-1] * i) % m)
    
out = 0

for size in range(1, n + 1):
    out += fact[size] * (n - size + 1) ** 2 * fact[n - size]
    out %= m

print(out)