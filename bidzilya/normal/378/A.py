def get_ints():
    return map(int, raw_input().split(' '))

a, b = get_ints()

ans = [0, 0, 0]

for i in xrange(1, 7):
    da = abs(a - i)
    db = abs(b - i)

    if da == db:
        ans[1] += 1
    elif da < db:
        ans[0] += 1
    else:
        ans[2] += 1
        
print ans[0], ans[1], ans[2]