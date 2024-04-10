n = int(raw_input())

ans = 0
for i in xrange(n):
    a, b, c = map(int, raw_input().split(' '))
    if a + b + c > 1:
        ans += 1

print ans