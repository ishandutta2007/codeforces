ri = lambda: map(int, raw_input().split())
n, m, k = ri()
print min(abs(m - 1 - i) * 10 for i, p in enumerate(ri()) if 0 < p <= k)