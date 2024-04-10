n = input() - 1
d = [[0] * 3 for i in xrange(3)]
d[0][1] = d[1][0] = input()
d[0][2] = d[2][0] = input()
d[1][2] = d[2][1] = input()
s = 0
c = 0
for i in xrange(n):
    t = [i for i in xrange(3) if i != c]
    if d[c][t[0]] < d[c][t[1]]:
        s += d[c][t[0]]
        c = t[0]
    else:
        s += d[c][t[1]]
        c = t[1]
print s