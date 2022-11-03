def get_ints():
    return map(int, raw_input().split(' '))

n, v = get_ints()
ans = []
for i in xrange(n):
    s = get_ints()
    k = s[0]
    s = s[1:]
    m = min(s)
    if m < v:
        ans.append(i + 1)

print len(ans)
for i in ans:
    print i,