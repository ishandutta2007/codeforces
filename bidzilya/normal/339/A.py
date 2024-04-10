l = raw_input().split('+')
l.sort()
for i in xrange(len(l)):
    l[i] = l[i] + '+'
ans = ''
for i in l:
    ans = ans + i
print ans[0 : len(ans) - 1]