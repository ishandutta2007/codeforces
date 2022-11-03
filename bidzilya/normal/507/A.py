n, t = map(int, raw_input().split(' '))
a = zip(map(int, raw_input().split(' ')), range(n))

a.sort()

ans = []
for i in xrange(n):
    if a[i][0] <= t:
        t -= a[i][0]
        ans.append(a[i][1])

print len(ans)
for i in ans:
    print i + 1,