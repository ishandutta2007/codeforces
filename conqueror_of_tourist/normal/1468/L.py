from math import gcd

def t_prime(n):
    if n == 1:
        return False
    for p in [2,3,5,7,11,13,17,19,23]:
        if p < n and pow(p,n-1,n) != 1:
            return False
    return True

primes = [i for i in range(2,10**5) if t_prime(i)]
pset = set(primes)
        
n, k = map(int, input().split())
l = list(map(int, input().split()))

if k == 1:
    print(0)
    exit()

for i in range(n):
    for j in range(i):
        u, v = l[i], l[j]
        poss = gcd(u,v)
        poss2 = max(u,v)//poss
        smol = min(poss,poss2)
        if t_prime(smol) and smol not in pset:
            primes.append(smol)
            pset.add(smol)

powers = set()

count = 0
outLs = []
pgood = []
for p in primes:
    curr = []
    fp = [v for v in l if v % p == 0]
    for v in fp:
        v2 = v
        while v2 % p == 0:
            v2 //= p
        if v2 == 1:
            curr.append(v)
            powers.add(v)
    if len(curr) > 1:
        count += len(curr)
        outLs.append(curr)
        pgood.append(p)

order = [(len(lis), lis) for lis in outLs]
order.sort(key = lambda x: x[0])

if len(order) == 0:
    print(0)
    exit()

if order[-1][0] == 2 and k % 2 and count > k:
    extra = -1
    need = -1
    last = []
    
    for v in l:
        if v in powers:
            continue
        
        v2 = v
        primesn = []
        for p in pgood:
            add = 1
            while v2 % p == 0:
                v2 //= p
                if add:
                    primesn.append(p)
                add = 0
        if v2 == 1 and (need == -1 or need > len(primesn)):
            extra = v
            last = primesn
            need = len(last)
            assert need >= 2
    
    if need == -1 or 2 * need + 1 > k:
        print(0)
        exit()
    
    other = []
    out = [extra]
    
    for a,b in outLs:
        works = False
        for p in last:
            if a % p == 0:
                works = True
                break
        if works:
            out.append(a)
            out.append(b)
        else:
            other.append(a)
            other.append(b)

    assert len(out) == 2 * need + 1
    assert (k - 2 * need - 1) % 2 == 0

    ret = out + other[:(k - 2*need - 1)]
    assert len(ret) == k
    
    print(' '.join(map(str,ret)))
    exit()

out = []
need = k
for i in range(len(order)):
    assert need != 1
    
    lis = order[i][1]
    if len(lis) < need - 1 or len(lis) == need or (len(lis) == need - 1 and i == len(order) - 1):
        out += lis
        need -= len(lis)
    elif len(lis) == need - 1:
        if len(lis) > 2:
            out += lis[:-1]
            need -= (len(lis) - 1)
            assert need == 2
    else:
        out += lis[:need]
        need = 0
        
assert need + len(out) == k
assert need >= 0
assert need == 0 or len(out) == count

for v in l:
    if need == 0:
        break

    
    if v in powers:
        continue
    
    v2 = v
    for p in pgood:
        while v2 % p == 0:
            v2 //= p
    if v2 == 1:
        out.append(v)
        need -= 1
    
    

if need == 0:
    print(' '.join(map(str,out)))
    exit()
else:
    print(0)