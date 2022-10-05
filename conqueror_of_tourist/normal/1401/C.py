import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    s = sorted(l)
    for i in range(n):
        if l[i] != s[i] and l[i] % s[0] != 0:
            print('NO')
            break
    else:
        print('YES')