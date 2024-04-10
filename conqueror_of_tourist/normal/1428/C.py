import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()
    out = 0
    for c in s:
        if c == 'B' and out:
            out -= 1
        else:
            out += 1
    print(out)