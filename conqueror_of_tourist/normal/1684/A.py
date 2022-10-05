import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    s = input().strip()

    if len(s) == 2:
        print(s[1])
    else:
        print(min(list(s)))