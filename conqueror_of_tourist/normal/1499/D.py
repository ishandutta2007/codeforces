MAX = 2 * 10 ** 7 + 1
pfo = [1] * MAX
large = [0] * MAX
out = 0
for i in range(2, MAX):
    if pfo[i] == 1:
        out += 1
        for j in range(i, MAX, i):
            pfo[j] *= 2
            large[j] = i

out = []
t = int(input())
for _ in range(t):
    c,d,x = map(int, input().split())
    
    pf = []
    curr = x
    while curr > 1:
        pf.append(large[curr])
        curr //= large[curr]
    pf.sort()
    factors = [1]
    for p in pf:
        new = []
        for f in factors:
            new.append(p * f)
            if f % p:
                new.append(f)
        factors = new

    out.append(0)
    for f in factors:
        if (f + d) % c == 0:
            k = (f + d) // c
            out[-1] += pfo[k]
print('\n'.join(map(str,out)))