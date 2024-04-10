import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    out = [-1] * n
    for i in range(n):
        if a[i] != out[(i-1) % n] and a[i] != out[(i+1) % n]:
            out[i] = a[i]
        if b[i] != out[(i-1) % n] and b[i] != out[(i+1) % n]:
            out[i] = b[i]
        if c[i] != out[(i-1) % n] and c[i] != out[(i+1) % n]:
            out[i] = c[i]
        
    print(' '.join(map(str,out)))