s = int(input())

out = 0

for l in range(60):
    for r in range(60):
        lm = (1 << (l + 1)) - 1
        rm = (1 << (r + 1)) - 1 

        mult = lm + rm - 1

        ss = s
        #Forgot about right min
        poss = []
        for i in range(l):
            poss.append((1 << i) - 1)
            
        for i in range(r):
            poss.append((1 << i) - 1)
            ss -= 1 << i

        
        base = ss // mult
        if base < 1:
            continue

        rem = ss % mult

        poss.sort(reverse = True)
        while poss and poss[-1] == 0:
            poss.pop()

        ct = {rem : 1}
        msz = 0

        #print(rem, poss)
        m = len(poss)
        for i in range(m):
            s_rem = sum(poss[i:])
            u = poss[i]
            nct = {}

            def add(a, b):
                if a not in nct:
                    nct[a] = b
                else:
                    nct[a] += b
            
            for v in ct:
                if v > s_rem or v < 0:
                    continue

                add(v, ct[v])
                add(v - u, ct[v])
            
            #print(ct)    
            ct = nct
            msz = max(msz, len(ct))
        #print(msz)
        if 0 in ct:
            out += ct[0]
print(out)