a = input()
b = []
for x in xrange(a):
    b.append(raw_input())

g = []

ok =True
for x in xrange(a):
    if '.' not in b[x]:
        ok = False
        break
    else:
        g.append((x + 1,b[x].index('.') + 1))

if ok:
    for x in g:
        print x[0], x[1]
    exit()

d = [[] for x in xrange(a)]
for x in xrange(a):
    for y in xrange(a):
        d[x].append(b[y][x])
    d[x] = ''.join(d[x])

g = []
b = d
ok = True
for x in xrange(a):
    if '.' not in b[x]:
        ok = False
        break
    else:
        g.append((x + 1,b[x].index('.') + 1))
if ok:
    for x in g:
        print x[1], x[0]
    exit()

print -1