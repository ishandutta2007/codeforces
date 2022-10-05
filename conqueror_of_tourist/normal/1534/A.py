import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    poss = [True, True]
    for i in range(n):
        s = input()
        for j in range(m):
            c = s[j]
            if c == 'R':
                poss[(i + j) % 2] = False
            elif c == 'W':
                poss[(i + j + 1) % 2] = False
    s1 = ''.join('R' if i % 2 else 'W' for i in range(m))
    s0 = ''.join('W' if i % 2 else 'R' for i in range(m))
    if poss[0]:
        print('YES')
        print('\n'.join(s0 if i % 2 else s1 for i in range(n)))
    elif poss[1]:
        print('YES')
        print('\n'.join(s1 if i % 2 else s0 for i in range(n)))
    else:
        print('NO')