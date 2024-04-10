import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    n = len(s)
    x = int(input())
    outl = ['1'] * n
    for i in range(n):
        if s[i] == '0':
            if i >= x:
                outl[i-x] = '0'
            if i + x < n:
                outl[i+x] = '0'
    out = ''.join(outl)
    works = True
    for i in range(n):
        if s[i] == '1':
            if (i < x or out[i - x] == '0') and (i + x >= n or out[i + x] == '0'):
                works = False
                break

    if works:
        print(out)
    else:
        print(-1)