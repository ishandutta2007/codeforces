n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

best = -1
sel = -1
for i in range(k):
    cur = n - n % a[i]
    if best < cur:
        best = cur
        sel = i

print('%d %d' % (sel + 1, n // a[sel]))