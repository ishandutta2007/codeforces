import sys
input = sys.stdin.readline

from functools import cmp_to_key

def cmp(t1, t2):
    return t1[0] * t2[1] - t1[1] * t2[0]

out = []
t = int(input())
for _ in range(t):
    n, m  = map(int,input().split())
    a = list(map(int, input().split()))
    a.sort()
    a = a[-m:]

    outS = []
    outST = []
    
    gl = []
    g = []
    sg = []
    for i in range(m):
        gl.append(int(input()))
        g.append(list(map(int, input().split())))
        sg.append(sum(g[-1]))

    gOrd = [(sg[i], gl[i], i) for i in range(m)]
    gOrd.sort(key = cmp_to_key(cmp))

    pos = [-1] * m
    for i in range(m):
        pos[gOrd[i][2]] = i

    good = [a[i] * gOrd[i][1] >= gOrd[i][0] for i in range(m)]
    goodL = [a[i + 1] * gOrd[i][1] >= gOrd[i][0] for i in range(m - 1)]
    goodR = [a[i - 1] * gOrd[i][1] >= gOrd[i][0] for i in range(1, m)]
    
    goodLM = []
    curr = 0
    for i in range(m - 1):
        if goodL[i]:
            curr += 1
        else:
            curr = 0
        goodLM.append(curr)

    goodRM = []
    curr = 0
    for i in range(m - 1):
        if goodR[i]:
            curr += 1
        else:
            curr = 0
        goodRM.append(curr)

    goodPre = []
    curr = 1
    for i in range(m):
        if good[i]:
            curr *= 1
        else:
            curr = 0
        goodPre.append(curr)

    goodPost = [0] * m
    curr = 1
    for i in range(m - 1, -1, -1):
        if good[i]:
            curr *= 1
        else:
            curr = 0
        goodPost[i] = curr
    


    if all(good):
        for ii in range(m):
            for v in g[ii]:
                ns = sg[ii] - v
                nl = gl[ii] - 1

                oldInd = pos[ii]

                nt = (ns, nl)
                if cmp(nt, (sg[ii], gl[ii])) <= 0:
                    outS.append('1')
                    continue

                lo = -1 #>
                hi = m #<=
                while hi - lo > 1:
                    ts = (lo + hi)//2
                    if cmp(nt, gOrd[ts]) <= 0:
                        hi = ts
                    else:
                        lo = ts

                assert hi > oldInd
                nInd = hi - 1
                assert nInd >= oldInd

                if (nl * a[nInd] >= ns) and (nInd == 0 or goodRM[nInd - 1] >= nInd - oldInd):
                    outS.append('1')
                else:
                    outS.append('0')
    else:
        for ii in range(m):
            for v in g[ii]:
                ns = sg[ii] - v
                nl = gl[ii] - 1

                oldInd = pos[ii]

                nt = (ns, nl)
                if cmp(nt, (sg[ii], gl[ii])) >= 0:
                    outS.append('0')
                    continue

                lo = -1 #>
                hi = m #<=
                while hi - lo > 1:
                    ts = (lo + hi)//2
                    if cmp(nt, gOrd[ts]) < 0:
                        hi = ts
                    else:
                        lo = ts

                
                assert hi <= oldInd
                nInd = hi


                #print(ns/nl, nInd)
                
                b1 = (nl * a[nInd] >= ns)
                b2 = (oldInd == nInd or goodLM[oldInd - 1] >= oldInd - nInd)
                b3 = nInd == 0 or goodPre[nInd - 1]
                b4 = oldInd == m - 1 or goodPost[oldInd + 1]

                #print(ii, v ,b1, b2, b3, b4, oldInd, nInd)

                if b1 and b2 and b3 and b4:
                    outS.append('1')
                else:
                    outS.append('0')

    '''
    for ii in range(m):
        for v in g[ii]:
            ns = sg[ii] - v
            nl = gl[ii] - 1
            
            gOrdD = [(sg[i], gl[i], i) for i in range(m)]
            gOrdD[ii] = (ns, nl, ii)

            gOrdD.sort(key = cmp_to_key(cmp))
            good = [a[i] * gOrdD[i][1] >= gOrdD[i][0] for i in range(m)]
            #print(ii, gOrdD)
            if all(good):
                outST.append('1')
            else:
                outST.append('0')
    assert outST == outS'''
    
    out.append(''.join(outS))
print('\n'.join(map(str,out)))