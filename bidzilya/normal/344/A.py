n = int(raw_input())
last_bit = -1
ans = 0
for i in xrange(n):
    x = raw_input()
    if (last_bit == -1 or last_bit == x[0]):
        ans += 1
    last_bit = x[1]
print ans