n, m = map(int, raw_input().split(' '))
a = []
row = [0] * n
col = [0] * m
for i in xrange(n):
    a.append(raw_input())
    for j in xrange(m):
        if a[i][j] == 'S':
            row[i] += 1
            col[j] += 1

ans = n * m
for i in xrange(n):
    for j in xrange(m):
        if row[i] > 0 and col[j] > 0:
            ans -= 1
            
print ans