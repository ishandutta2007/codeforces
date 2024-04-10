n, t, k, d = map(int, raw_input().split())

a = (n + k - 1) / k * t

b = d + t

print 'YES' if b < a else 'NO'