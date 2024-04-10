import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int ,input().split()))
    
    for i in range(n - 1, -1 , -1):
        if a[i] != i + 1:
            break
        
    low = i + 1
    p_f = 0
    if low <= 1:
        p_f = 1
    
    for q in range(m):
        r, p = input().split()
        if int(r) >= low:
            p = float(p)
            p_f = p + (1 - p) * p_f
    print(p_f)