import sys
input = sys.stdin.readline

t = int(input())
for test in range(t):
    if test:
        input()
    n, m = map(int, input().split())
    a = [-1] * m
    b = [-1] * m

    for i in range(m):
        a[i], b[i] = map(int, input().split())

    l = [(a[i],0,i) for i in range(m)] + [(b[i],1,i) for i in range(m)]
    l.sort(reverse = True)
    
    count = 0
    tot = 0
    best = 0
    used = [False] * m
    for good, typ, ind in l:
        if typ == 0:
            count += 1
            tot += good
            used[ind] = True
            if count == n:
                best = max(best, tot)
                break
        else:
            curr = tot
            curr += good * (n - count)
            if not used[ind]:
                curr -= good
                curr += a[ind]
            best = max(curr,best)
    print(best)