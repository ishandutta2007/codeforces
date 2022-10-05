import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    s = input()
    l = ['']*k
    works = True
    for i in range(n):
        c = s[i]
        if c != '?':
            if l[i%k] == c or l[i%k] == '':
                l[i%k] = c
            else:
                works = False
                break
    if works:
        smol = 0
        big = k
        for c in l:
            if c == '0':
                big -= 1
            elif c == '1':
                smol += 1
        goal = k//2
        if smol <= goal <= big:
            print('YES')
        else:
            print('NO')
    else:
        print('NO')