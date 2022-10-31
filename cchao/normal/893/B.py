n = input()
ans = 1
for k in xrange(1, 32):
    x = ((1 << k) - 1) << (k - 1)
    if n % x == 0:
        ans = x
print ans