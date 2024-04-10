import sys
input = sys.stdin.readline

t = int(input())
out = []
for i in range(t):
    n = int(input())
    l = list(map(lambda x: int(x) % n, input().split()))

    taken = [False] * n
    for i in range(n):
        taken[(i + l[i]) % n] = True
    
    for i in range(n):
        if not taken[i]:
            out.append('NO')
            break
    else:
        out.append('YES')
print('\n'.join(out))