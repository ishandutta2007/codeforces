n, k = map(int, raw_input().split())
print int(k > 0 and k < n), min(k * 2, n - k)