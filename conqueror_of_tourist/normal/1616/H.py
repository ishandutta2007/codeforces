n, x = map(int, input().split())

a = list(map(int, input().split()))

MOD = 998244353

def modmul(x, y):
    return (x * y) % MOD

def solve1(l, ind):
    if l == []:
        return 0
    if ind < 0:
        return pow(2, len(l), MOD) - 1

    mask = 1 << ind

    if x & mask:
        z = []
        o = []
        for v in l:
            if v & mask:
                z.append(v)
            else:
                o.append(v)
        out = 0
        #print(l, z, o)
        out += pow(2, len(z), MOD) - 1
        out += pow(2, len(o), MOD) - 1
        out += solve2(o, z, ind - 1)
        return out % MOD
    else:
        out = 0
        z = []
        o = []
        for v in l:
            if v & mask:
                z.append(v)
            else:
                o.append(v)
        out += solve1(z, ind - 1)
        out += solve1(o, ind - 1)
        return out % MOD

def solve2(l, r, ind):
    if l == []:
        return 0
    if r == []:
        return 0
    if ind < 0:
        return modmul(pow(2, len(l), MOD) - 1, pow(2, len(r), MOD) - 1)

    mask = 1 << ind
    if x & mask:
        zl = []
        ol = []
        for v in l:
            if v & mask:
                zl.append(v)
            else:
                ol.append(v)

        zr = []
        o_r = []
        for v in r:
            if v & mask:
                zr.append(v)
            else:
                o_r.append(v)
        #print(l, r , zl, ol, zr, o_r, ind)
        
        out1 = solve2(zl, o_r, ind - 1)
        out2 = solve2(zr, ol, ind - 1)

        #print(out1, out2)

        out = 0

        out += modmul(pow(2, len(zl), MOD) - 1, pow(2, len(zr), MOD) - 1)
        out += modmul(pow(2, len(ol), MOD) - 1, pow(2, len(o_r), MOD) - 1)
        out += modmul(out1, out2)
        out += modmul(out1, pow(2, len(ol), MOD) + pow(2, len(zr), MOD) - 1)
        out += modmul(out2, pow(2, len(o_r), MOD) + pow(2, len(zl), MOD) - 1)
        return out % MOD
    else:
        zl = []
        ol = []
        for v in l:
            if v & mask:
                zl.append(v)
            else:
                ol.append(v)

        zr = []
        o_r = []
        for v in r:
            if v & mask:
                zr.append(v)
            else:
                o_r.append(v)
                
        out1 = solve2(zl, zr, ind - 1)
        out2 = solve2(ol, o_r, ind - 1)
        return (out2 + out1) % MOD
    
print(solve1(a, 29) % MOD)