cost = {'q': 9, 'r': 5, 'b': 3, 'n': 3, 'p': 1, 'k': 0}
s = [0, 0]
for i in xrange(8):
    a = raw_input()
    for c in a:
        if c == '.':
            continue
        indx = 0
        if c >= 'a' and c <= 'z':
            indx = 1
        s[indx] += cost[c.lower()]
if s[0] > s[1]:
    print 'White'
elif s[0] < s[1]:
    print 'Black'
else:
    print 'Draw'