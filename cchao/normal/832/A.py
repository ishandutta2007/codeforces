a, b = map(int, raw_input().split())
print ["NO", "YES"][(a / b) % 2]