a, b, c, d = list(map(int, input().split()))
s1 = min(a, c, d) * 256
a -= min(a, c, d)
s1 += min(a, b) * 32
print(s1)