import sys
input = sys.stdin.readline

n = int(input())
for _ in range(n):
    s, t = input().split()

    need = []
    
    for c in 'QWERTYUIOPASDFGHJKLZXCVBNM':
        ct = t.count(c)

        for i in range(len(s) - 1, -1, -1):
            if s[i] == c and ct:
                ct -= 1
                need.append(i)

    need.sort()

    tt = ''.join(s[i] for i in need)

    if t == tt:
        print('YES')
    else:
        print('NO')