import sys
input = sys.stdin.readline

outL = []
t = int(input())
for _ in range(t):
    n = int(input())
    s1 = input().strip()
    s2 = input().strip()
    s3 = input().strip()

    c1 = 0
    c2 = 0
    c3 = 0
    l = []
    while max(c1, c2, c3) < 2 * n:
        if s1[c1] == s2[c2] == s3[c3]:
            l.append(s1[c1])
            c1 += 1
            c2 += 1
            c3 += 1
        elif s1[c1] == s2[c2]:
            l.append(s1[c1])
            c1 += 1
            c2 += 1
        elif s2[c2] == s3[c3]:
            l.append(s2[c2])
            c2 += 1
            c3 += 1
        else:
            assert s1[c1] == s3[c3]
            l.append(s1[c1])
            c1 += 1
            c3 += 1

    rem = [(-c1,1),(-c2,2),(-c3,3)]
    rem.sort()
    _, add = rem[1]
    if add == 1:
        sn = s1
        cn = c1
    elif add == 2:
        sn = s2
        cn = c2
    else:
        sn = s3
        cn = c3
    l.append(sn[cn:])
    out = ''.join(l)
    if len(out) < 3 * n:
        out += '0'*(3 * n - len(out))
    outL.append(out)
print('\n'.join(outL))