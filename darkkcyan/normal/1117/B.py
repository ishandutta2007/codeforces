n, m, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
u, v = a[-2], a[-1]

print(m // (k + 1) * (v * k + u) + m % (k + 1) * v)