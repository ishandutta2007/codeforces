n = int(raw_input())
a = []
for i in xrange(n):
    a.append(map(int, raw_input().split(' ')))
ans = 0
for i in xrange(n):
    for j in xrange(n):
        if (i != j):
            if (a[i][0] == a[j][1]):
                ans += 1

print ans