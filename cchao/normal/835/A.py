s, v1, v2, t1, t2 = map(int, raw_input().split())
a = t1 * 2 + v1 * s
b = t2 * 2 + v2 * s

if a < b:
    print 'First'
elif a > b:
    print 'Second'
else:
    print 'Friendship'