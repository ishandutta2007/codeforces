import sys
input = sys.stdin.readline

t = int(input())

o = []
for _ in range(t):
    n, m = map(int, input().split())
    if n == 1 and m == 1:
        o.append(0)
    elif n == 1 or m == 1:
        o.append(1)
    else:
        o.append(2)
print('\n'.join(map(str,o)))