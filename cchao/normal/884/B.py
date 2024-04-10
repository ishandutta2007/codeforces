ri = lambda: map(int, raw_input().split())
n, x = ri()
print ["NO", "YES"][sum(ri()) + n - 1 == x]