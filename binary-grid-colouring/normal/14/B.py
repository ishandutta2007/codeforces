#coding:utf8
n, x= map(int, raw_input().split())
l,r = 0,1000
for i in xrange(n):
    a,b = sorted(map(int,raw_input().split()))
    l = max(l,a)
    r = min(r,b)
if l > r:
    print -1
elif x > r:
    print x - r
elif x < l:
    print l - x
else:
    print 0