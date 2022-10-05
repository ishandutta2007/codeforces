import sys
input = sys.stdin.readline

out = []
ssl = []
t = int(input())
for _ in range(t):
    n,a,b,c = map(int,input().split())
    s = input().strip()

    ssl.append(s)

    #if ssl[0] == '1111' and _ == 5099:
    #    print(n,a,b,c,s)

    z = [0]
    zc = 0
    oc = 0
    for ch in s:
        if ch == '0':
            z[-1] += 1
            zc += 1
        else:
            z.append(0)
            oc += 1

    M1 = sum(max(0, v - 1) for v in z)
    
    if len(z) == 1:
        out.append(a if n>=2 else 0)
        continue
    

    l = z.pop(0)
    r = z.pop()

    poss = [0]

    #StartOdd
    zz = sorted(z)[::-1]
    curr = 0
    L1 = M1
    L2 = 0
    Z1 = 0
    OL = oc
    ZL = zc
    while zz and zz[-1] == 0:
        zz.pop()
        L2 += 1

    while zz and zz[-1] == 1:
        zz.pop()
        Z1 += 1
    while True:
        if ZL == 0:
            break
        
        if L1 > 0:
            poss.append(curr + a)

        if OL <= 1:
            break

        if L2 > 0:
            if L1 > 0:
                curr += a
                ZL -= 1
                L1 -= 1
                if zz:
                    zz[-1] -= 1
                    if zz[-1] == 1:
                        zz.pop()
                        Z1 += 1
                
                curr += b
                L2 -= 1
                OL -= 1
            else:
                curr -= c
                ZL -= 1

                curr += b
                OL -= 1
        else:
            ZL -= 1

            if Z1 == 0:
                break
            
            Z1 -= 1
            curr -= c


            OL -= 1
            curr += b

            

            

        poss.append(curr)

    #StartEven
    zz = sorted(z)[::-1]
    curr = 0
    L1 = M1
    L2 = 0
    Z1 = 0
    OL = oc
    ZL = zc
    while zz and zz[-1] == 0:
        zz.pop()
        L2 += 1

    while zz and zz[-1] == 1:
        zz.pop()
        Z1 += 1

    #print(L2)
    good = False

    if L2:
        OL -= 1
        L2 -= 1
        curr = b
        poss.append(b)
        good = True

    while good:
        #print(curr,L1,L2,Z1,OL,ZL,poss)

        if ZL == 0:
            break
        
        if L1 > 0:
            poss.append(curr + a)

        if OL <= 1:
            break

        if L2 > 0:
            if L1 > 0:
                curr += a
                ZL -= 1
                L1 -= 1
                if zz:
                    zz[-1] -= 1
                    if zz[-1] == 1:
                        zz.pop()
                        Z1 += 1
                
                curr += b
                L2 -= 1
                OL -= 1
            else:
                curr -= c
                ZL -= 1

                curr += b
                OL -= 1
        else:
            ZL -= 1

            if Z1 == 0:
                break
            
            Z1 -= 1
            curr -= c
            
            OL -= 1
            curr += b            

        poss.append(curr)
                
    #print()
    out.append(max(poss))
print('\n'.join(map(str,out)))