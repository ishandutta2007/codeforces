import sys
n = int(input())
if n % 2:
    print('Second')
    sys.stdout.flush()
    l = list(map(lambda x: int(x)-1,input().split()))
    rev1 = [-1]*n
    rev2 = [-1]*n
    revs = [0]*n
    for i in range(2 * n):
        revs[l[i]] += i
        if rev1[l[i]] == -1:
            rev1[l[i]] = i
        else:
            rev2[l[i]] = i

    out = [0] * (2 * n)
    curr = 0
    todo = 2*n
    q = []
    while todo:
        while out[curr] and curr < 2*n:
            curr += 1
        if curr == 2*n:
            break
            
        out[curr] = 1
        todo -= 1
        q = [curr]
        while q:
            v = q.pop()
            mod = v % n
            other = (2 * mod + n) - v
            if out[other] == 0:
                out[other] = 3 - out[v]
                todo -= 1
                q.append(other)
            other = revs[l[v]] - v
            if out[other] == 0:
                out[other] = 3 - out[v]
                todo -= 1
                q.append(other)
    s1 = 0
    for i in range(2 * n):
        if out[i] == 1:
            s1 += i + 1
    if s1 % (2 * n) == 0:
        want = 1
    else:
        want = 2
    rout = []
    for i in range(2 * n):
        if out[i] == want:
            rout.append(i + 1)
    print(' '.join(map(str,rout)))
    sys.stdout.flush()
else:
    print('First')
    sys.stdout.flush()
    l = [1+(i%n) for i in range(2*n)]
    print(' '.join(map(str,l)))
    sys.stdout.flush()