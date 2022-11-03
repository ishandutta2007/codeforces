n, m = map(int, raw_input().split(' '))
a = map(int, raw_input().split(' '))

while True:
    changed = False
    for i in xrange(n):
        if a[i] > 0:
            a[i] = max(a[i] - m, 0)
            last = i
            changed = True
    if not changed:
        break
    
print last + 1