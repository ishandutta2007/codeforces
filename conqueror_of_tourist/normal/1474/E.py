import sys
input = sys.stdin.readline

out = []
t = int(input())
for _ in range(t):
    n = int(input())
    curr = list(range(1,n+1))
    ops = []
    val = 0
    for i in range(n//2,n):
        ops.append(f'{i + 1} 1')
        curr[0], curr[i] = curr[i], curr[0]
        val += i * i
    for i in range(1,n//2):
        ops.append(f'{i + 1} {n}')
        curr[-1], curr[i] = curr[i], curr[-1]
        val += (n-1-i) * (n-1-i)
    ops.reverse()
    
    out.append(str(val))
    out.append(' '.join(map(str,curr)))
    out.append(str(len(ops)))
    out.append('\n'.join(ops))
print('\n'.join(out))