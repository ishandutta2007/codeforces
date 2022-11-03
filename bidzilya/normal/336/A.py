def get_ints():
    return map(int, raw_input().strip().split(' '))

x, y = get_ints()

if x > 0 and y > 0:
    print 0, x + y, x + y, 0
elif x > 0 and y < 0:
    print 0, -(x + abs(y)), x + abs(y), 0
elif x < 0 and y > 0:
    print -(abs(x) + y), 0, 0, abs(x) + y
else:
    print x + y, 0, 0, x + y