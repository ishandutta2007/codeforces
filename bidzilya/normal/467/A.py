n = int(raw_input())
ans = 0
for i in xrange(n):
    a, b = map(int, raw_input().split(' '))
    if a + 2 <= b:
        ans += 1
print ans