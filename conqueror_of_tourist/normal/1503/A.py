import sys,io,os
try:input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
except:input=lambda:sys.stdin.readline().encode()

out = []

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()

    c1 = 0
    for c in s:
        if c == 49:
            c1 += 1

    if c1 % 2 == 1:
        out.append('NO')
        continue

    s1 = []
    s2 = []

    ac = 0
    bc = 0
    works = True

    r1 = c1//2
    toggle = 0
    for c in s:
        if c == 49:
            if r1:
                s1.append('(')
                s2.append('(')
                ac += 1
                bc += 1
                r1 -= 1
            else:
                s1.append(')')
                s2.append(')')
                ac -= 1
                bc -= 1
        else:
            if toggle:
                s1.append(')')
                s2.append('(')
                ac += 1
                bc -= 1
            else:
                s1.append('(')
                s2.append(')')
                ac -= 1
                bc += 1
            toggle ^= 1
        if ac < 0 or bc < 0:
            works = False
            break

    if works:
        assert ac == 0 and bc == 0
        out.append('YES')
        out.append(''.join(s1))
        out.append(''.join(s2))
    else:
        out.append('NO')
print('\n'.join(out))