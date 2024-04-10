import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    a, b = map(int, input().split())
    out = set()
    n  =(a+b)
    
    aa = (a+b)//2
    bb = n - aa
    mb = max(a-aa,b-bb)
    extra = min(a,b)
    for i in range(mb,mb+2*extra+1,2):
        out.add(i)

    aa = (a+b+1)//2
    bb = n - aa
    mb = max(a-aa,b-bb)
    extra = min(a,b)
    for i in range(mb,mb+2*extra+1,2):
        out.add(i)
    out = sorted(out)
    print(len(out))
    print(' '.join(map(str,out)))