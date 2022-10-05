t = int(input())
for _ in range(t):
    works = 0
    n = int(input())
    ps = []
    for i in range(2,4*10**4):
        c = 0
        while n % i == 0:
            c += 1
            n //= i
        if c:
            ps.append((i,c))
    if n > 1:
        ps.append((n,1))
    if len(ps) >= 3:
        base = [0] * (2 * len(ps))
        lists = [[] for i in range(2 * len(ps))]
        for i in range(len(ps)):
            base[2*i] = ps[i][0]
            base[2*i+1] = ps[i][0] * ps[(i + 1)%len(ps)][0]
            factors = [1]

        for p,pp in ps:
            mult = [pow(p,i) for i in range(pp+1)]
            new = []
            for m in mult:
                for f in factors:
                    new.append(m*f)
            factors = new
        
        for v in factors:
            if v in base:
                lists[base.index(v)] += [v]
            else:
                for u in range(2*len(ps)):
                    if v % base[u] ==0:
                        lists[u] += [v]
                        break
    
        out=sum(lists,[])
    elif len(ps) == 2:
        p, q = ps
        if p[1] < q[1]:
            p,q=q,p
        p, pp = p
        q, qq = q
        if pp == 1 and qq == 1:
            works = 1
            out = [p,p*q,q]
        else:
            base = [p,p*q,q,p*p*q]
            lists = [[],[],[],[]]
            for i in range(pp + 1):
                for j in range(qq + 1):
                    v = pow(p,i) * pow(q,j)
                    if v in base:
                        lists[base.index(v)] += [v]
                    else:
                        for u in range(4):
                            if v % base[u]==0:
                                lists[u] += [v]
                                break
            out=sum(lists,[])
            
    else:
        out = []
        for i in range(1, ps[0][1]+1):
            out.append(pow(ps[0][0],i))
    print(' '.join(map(str,out)))
    print(works)