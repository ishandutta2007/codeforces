import sys,io,os;input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t):
    n, m, a, b = map(int, input().split())
    f = list(map(int, input().split()))
    f.sort()
    out = 0
    
    if a > b:
        a = n - a + 1
        b = n - b + 1
    
    maxDrop = b - a - 1
    maxTime = b - 2
    
    for i in range(maxDrop):
        while f:
            v = f.pop()
            if v <= maxTime - i:
                out += 1
                break
        
        if len(f) == 0:
            break
    print(out)