n, k = map(int, input().split())
o = sum(int(x) & 1 for x in input().split())
e, k = n - o, n - k
if not k:
    w = o & 1
elif k & 1:
    if ((n - k) & 1) and o <= (k >> 1):
        w = 0
    elif min(o, e) <= (k >> 1) and not ((n - k) & 1):
        w = 0
    else:
        w = 1
elif ((n - k) & 1) and e <= (k >> 1):
    w = 1
else:
    w = 0
print(['Daenerys', 'Stannis'][w])