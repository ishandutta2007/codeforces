import sys
input = sys.stdin.readline

out = []
t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = input().strip()
    b = input().strip()

    if (a[1-m:] == b[1-m:] and b[0] in a[:1-m]) or (m == 1 and b[0] in a):
        out.append('Yes')
    else:
        out.append('No')
        
print('\n'.join(map(str, out)))