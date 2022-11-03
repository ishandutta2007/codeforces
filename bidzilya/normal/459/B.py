n = int(raw_input())
a = map(int, raw_input().split(' '))
a.sort()
if a[0] == a[n - 1]:
    print 0, n * (n - 1) / 2
    exit()
l = 0
for x in a:
    if x == a[0]:
        l += 1
r = 0
for x in a:
    if x == a[n - 1]:
        r += 1

print a[n - 1] - a[0], l * r