def get_ints():
    return map(int, raw_input().split(' '))

n, k = get_ints()
f = []
t = []
for i in xrange(n):
    cf, ct = get_ints()
    f.append(cf)
    t.append(ct)

found = False
for i in xrange(n):
    if t[i] > k:
        val = f[i] - (t[i] - k)
    else:
        val = f[i]
    if found == False or val > ans:
        ans = val
        found = True

print ans