import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input()

    out = 0
    lCycle = True
    rCycle = True
    for c in s:
        if c == '<':
            lCycle = False
        if c == '>':
            rCycle = False

    if lCycle or rCycle:
        print(n)
    else:
        for i in range(n):
            if s[i] == '-' or s[(i-1) % n] == '-':
                out += 1
        print(out)