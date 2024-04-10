def get_ints():
    return map(int, raw_input().split(' '))

n = int(raw_input())
a = get_ints()

s = [0, 0, 0]
for i in xrange(n):
    s[i % 3] += a[i]

if s[0] == max(s):
    print 'chest'
elif s[1] == max(s):
    print 'biceps'
else:
    print 'back'