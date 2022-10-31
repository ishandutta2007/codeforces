ri = lambda: map(int, raw_input().split())
n, m = ri()
a = [ri() for i in xrange(m)]

s = set()

for l in xrange(1, 101):
    if all((x[0] - 1) / l + 1 == x[1] for x in a):
        s.add((n - 1) / l + 1)

if len(s) != 1:
    print -1
else:
    print next(iter(s))