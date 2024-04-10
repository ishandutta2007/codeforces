import sys,io,os
try:Z=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except:Z=lambda:sys.stdin.readline().encode()
input=Z

t = int(input())
pr = []
for _ in range(t):
    n = int(input())
    p = list(map(int, input().split()))

    M1 = [-n-1]
    M2 = [-n-1]
    pa = [-1]
    add = [-1]

    ct = 1

    curr = [0]
    for v in p:
        things = []
        for nex in [v, -v]:
            oof = []
            for ind in curr:
                m1 = M1[ind]
                m2 = M2[ind]
                if m2 > nex:
                    continue
                if m1 > nex:
                    m2 = nex
                else:
                    m1 = nex
                M1.append(m1)
                M2.append(m2)
                pa.append(ind)
                add.append(nex)
                oof.append(ct)
                ct += 1
            things.append(oof)
        c1, c2 = things

        a, b = len(c1), len(c2)
        i, j = 0, 0
        #nc = c1 + c2
        #nc.sort(key = lambda x: (M1[x], M2[x]))

        ncc = []
        best = 2 * n
        for _ in range(a + b):
            if i == a:
                x = c2[j]
                j += 1
            elif j == b:
                x = c1[i]
                i += 1
            else:
                if M1[c1[i]] < M1[c2[j]] or (M1[c1[i]] == M1[c2[j]] and M2[c1[i]] < M2[c2[j]]):
                    x = c1[i]
                    i += 1
                else:
                    x = c2[j]
                    j += 1
            if M2[x] < best:
                ncc.append(x)
                best = M2[x]
        curr = ncc
        assert len(curr) < 3
    if curr:
        pr.append('YES')
        cc = curr[0]
        oo = []
        while cc > 0:
            oo.append(add[cc])
            cc = pa[cc]
        pr.append(' '.join(map(str, oo[::-1])))
    else:
        pr.append('NO')
print('\n'.join(pr))