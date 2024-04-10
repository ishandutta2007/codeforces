import sys,io,os;input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
t = int(input())
outL = []
MOD = 10 ** 9 + 7
for _ in range(t):
    n = int(input())
    p = list(map(lambda x: int(x) - 1, input().split()))

    if n % 3 == 0:
        ans = pow(3, n // 3, MOD)
    if n % 3 == 1:
        ans = pow(3, (n-4)//3, MOD) * 4
    if n % 3 == 2:
        ans = 2 * pow(3, (n-2)//3, MOD)
    ans %= MOD

    seen = [False] * n
    cycles = []
    for i in range(n):
        if seen[i]:
            continue
        count = 0
        curr = i
        while not seen[curr]:
            seen[curr] = True
            count += 1
            curr = p[curr]
        cycles.append(count)
    #print(cycles)

    if n % 3 == 0:
        out = 0
        c1 = 0
        c2 = 0
        for v in cycles:
            rem = (v - 1)//3
            out += rem
            v -= rem * 3
            assert 1 <= v <= 3
            if v == 1:
                c1 += 1
            if v == 2:
                c2 += 1
        cut = min(c1, c2)
        out += cut
        c1 -= cut
        c2 -= cut
        assert c1 % 3 == 0
        assert c2 % 3 == 0
        out += 2 * (c1 // 3)
        out += 3 * (c2 // 3)

    if n % 3 == 1:
        out = 0
        c1 = 0
        c2 = 0
        c4 = 0
        for v in cycles:
            rem = max(0,(v - 2)//3)
            out += rem
            v -= rem * 3
            assert 1 <= v <= 4
            if v == 1:
                c1 += 1
            if v == 2:
                c2 += 1
            if v == 4:
                c4 += 1

                
        if c4:
            c4 -= 1
            out += c4
            c1 += c4
            c4 += 1

        def solve(c1, c2):
            ret = 0
            if c2 >= 2:
                c2 -= 2
            elif c2 == 1:
                c2 -= 1
                c1 -= 2
                ret += 1
            else:
                if c1 > 1:
                    c1 -= 4
                    ret += 2
                else:
                    c1 -= 1
                    ret += 1
            cut = min(c1, c2)
            ret += cut
            c1 -= cut
            c2 -= cut
            assert c1 % 3 == 0
            assert c2 % 3 == 0
            ret += 2 * (c1 // 3)
            ret += 3 * (c2 // 3)

            return ret

        if c4:
            o1 = out + 1 + solve(c1 + 1, c2)
            cut = min(c1, c2)
            out += cut
            c1 -= cut
            c2 -= cut
            assert c1 % 3 == 0
            assert c2 % 3 == 0
            out += 2 * (c1 // 3)
            out += 3 * (c2 // 3)

            out = min(out, o1)
        else:
            out += solve(c1, c2)
            
        
    if n % 3 == 2:
        out = 0
        c1 = 0
        c2 = 0
        for v in cycles:
            rem = (v - 1)//3
            out += rem
            v -= rem * 3
            assert 1 <= v <= 3
            if v == 1:
                c1 += 1
            if v == 2:
                c2 += 1

        if c2:
            c2 -= 1
        else:
            c1 -= 2
            out += 1
                
        cut = min(c1, c2)
        out += cut
        c1 -= cut
        c2 -= cut
        assert c1 % 3 == 0
        assert c2 % 3 == 0
        out += 2 * (c1 // 3)
        out += 3 * (c2 // 3)

    outL.append(str(ans) + ' ' + str(out))

print('\n'.join(outL))