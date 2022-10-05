import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())

    l = list(map(int, input().split()))

    bad = -1

    for i in range(n - 1):
        if l[i] > l[i + 1]:
            bad = i

    if bad == -1:
        print(0)
        continue

    res = []

    for i in range(n):
        poss = l[:i] + l[i + 1:] + [x]
        poss.sort()


        ct = 0
        bad = False

        for i in range(n):
            if poss[i] < l[i]:
                ct += 1
            elif poss[i] > l[i]:
                bad = True

        #print(poss, bad)

        if not bad:
            res.append(ct)

    if res == []:
        print(-1)
    else:
        print(min(res))