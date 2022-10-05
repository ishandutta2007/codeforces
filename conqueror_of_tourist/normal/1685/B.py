import sys
input = sys.stdin.readline

out = []

t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    s = input().strip()
    n = len(s)

    aCount = s.count('A')

    if a + c + d != aCount:
        out.append('NO')
        continue

    astart = []
    bstart = []

    left = 0
    for i in range(1, n + 1):
        if i == n or s[i] == s[i - 1]:
            right = i
            if s[left] == 'A':
                astart.append(right - left)
            else:
                bstart.append(right - left)
            left = right

    astart.sort()
    bstart.sort()

    ab = []
    wild = 0
    ba = []

    for v in astart:
        if v % 2 == 1:
            wild += (v // 2)
        else:
            ab.append(v // 2)

    for v in bstart:
        if v % 2 == 1:
            wild += (v // 2)
        else:
            ba.append(v // 2)

    abt = sum(ab)
    bat = sum(ba)

    if abt + wild + bat < c + d:
        out.append('NO')
        continue

    while abt + wild < c and ba:
        u = ba.pop() - 1
        abt += u
        ab.append(u)

    while bat + wild < d and ab:
        u = ab.pop() - 1
        bat += u
        ba.append(u)

    if sum(ab) + wild + sum(ba) < c + d:
        out.append('NO')
        continue
        

    out.append('YES')

print('\n'.join(out))