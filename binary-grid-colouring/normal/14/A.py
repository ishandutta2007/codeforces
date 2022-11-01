#coding:utf8
n, m = map(int, raw_input().split())
s = [raw_input( ) for i in xrange(n)]
x1,y1,x2,y2 = n,m,0,0
for i in xrange(n):
    for j in xrange(m):
        if s[i][j] == '*':
            x1 = min(x1,i)
            y1 = min(y1,j)
            x2 = max(x2,i)
            y2 = max(y2,j)

for i in xrange(x1,x2+1):
    print s[i][y1:y2+1]