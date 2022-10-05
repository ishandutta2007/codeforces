import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    s = input().strip()
    bad = []
    for i in range(n):
        val = int(s[i:i+n],2)
        bad.append(2 ** n - val - 1)
    for i in range(n + 5):
        if i not in bad:
            break
    out = bin(i)[2:]
    while len(out) < n:
        out = '0' + out
    print(out)