import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = input().strip()
    out = []
    for i in range(1, len(n) + 1):
        if n[-i] != '0':
            out.append(n[-i]+'0'*(i - 1))
    print(len(out))
    print(*out)