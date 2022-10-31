a, b = map(int, raw_input().split())
for i in xrange(b):
    a = a / 10 if a % 10 == 0 else a - 1
print a