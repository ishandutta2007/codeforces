import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    if l[0] < l[-1]:
        out.append('YES')
    else:
        out.append('NO')
print('\n'.join(out))