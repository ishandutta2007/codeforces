import sys
input = sys.stdin.readline

n, m = map(int, input().split())
mask = (1 << m) - 1

l = []
for i in range(n):
    l.append(list(map(int,input().split())))

lo = -1 #Possible
hi = 10 ** 9 + 1 #Impossible
while hi - lo > 1:
    test = (hi + lo) // 2

    things = dict()
    for i in range(n):
        curr = 0
        for v in l[i]:
            curr *= 2
            if v >= test:
                curr += 1
        things[curr] = i

    works = False
    for v1 in things:
        for v2 in things:
            if v1 | v2 == mask:
                outi = things[v1]
                outj = things[v2]
                works = True
                break
        if works:
            break

    if works:
        lo = test
    else:
        hi = test

print(outi + 1, outj + 1)