import sys
input = sys.stdin.readline

t = int(input())
out = []
for _ in range(t):
    n, k = map(int, input().split())
    if k == 0:
        for i in range(n // 2):
            out.append(' '.join(map(str,[i, n - 1 - i])))
    elif k == n - 1:
        if n == 4:
            out.append('-1')
        else:
            out.append(f'{n-1} {n - 2}')
            out.append('0 2')
            out.append(f'{n-3} 1')
            for i in range(3, n // 2):
                out.append(' '.join(map(str,[i, n - 1 - i])))
    else:
        out.append(f'{n-1} {k}')
        out.append(f'0 {n - 1 - k}')
        for i in range(1, n // 2):
            if i not in (k, n-k-1):
                out.append(' '.join(map(str,[i, n - 1 - i])))

print('\n'.join(out))