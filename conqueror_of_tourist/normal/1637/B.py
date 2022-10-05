t = int(input())
for _ in range(t):
    n = int(input())
    out = 0
    for i in range(1, n + 1):
        out += i * (n + 1 - i)
        
    a = list(map(int, input().split()))
    for i in range(n):
        if a[i] == 0:
            out += (i + 1) * (n - i)
    print(out)