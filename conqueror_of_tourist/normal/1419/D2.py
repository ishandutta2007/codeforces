n = int(input())
a = list(map(int, input().split()))
a.sort()
lo = 0
hi = (n+1)//2
while hi - lo > 1:
    test = (hi + lo)//2
    smol = a[:test]
    large = a[-test-1:]
    rest = a[test:-test-1]
    works = True
    for i in range(test):
        if smol[i] == large[i] or smol[i] == large[i+1]:
            works = False
    if works:
        lo = test
    else:
        hi = test
smol = a[:lo]
large = a[-lo-1:]
rest = a[lo:-lo-1]
o = []
while smol:
    o += [large.pop()]
    o += [smol.pop()]
o += large
o += rest
print(lo)
print(' '.join(map(str,o)))