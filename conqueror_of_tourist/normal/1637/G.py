import sys
input = sys.stdin.readline

out = []

p2 = []
curr = 1
for i in range(2 * 10 ** 5):
    if i >= curr:
        curr *= 2
    p2.append(curr)

t = int(input())
for _ in range(t):
    ops = []
    l = []
    n = int(input())

    if n == 2:
        out.append(-1)
        continue

    def solve(m, mult):
        if m <= 2:
            for i in range(m):
                l.append((i + 1) * mult)
            return

        up = p2[m]
        l.append(mult * (up // 2))
        for i in range(up // 2 + 1, m + 1):
            ops.append((mult * i, mult * (up - i)))
            l.append(mult * up)

        solve(up - m - 1, mult)
        solve(m - (up // 2), mult * 2)

    solve(n, 1)
                       
    zc = 0
    curr = set()

    mx = p2[n-1]
    mxc = 0

    def add(v):
        global zc, mxc
        
        if v in curr:
            curr.remove(v)
            ops.append((v,v))
            zc += 1
            add(2 * v)
        else:
            if v == mx:
                mxc += 1
            else:
                curr.add(v)
        
    
    for v in l:
        assert v <= mx
        add(v)

    assert zc > 0

    for v in sorted(curr):
        while v != mx:
            ops.append((v, 0))
            ops.append((v, v))
            v *= 2

    while zc:
        ops.append((mx, 0))
        zc -= 1

    out.append(len(ops))
    for u, v in ops:
        out.append(str(u) + ' ' + str(v))
        
            
        
print('\n'.join(map(str,out)))