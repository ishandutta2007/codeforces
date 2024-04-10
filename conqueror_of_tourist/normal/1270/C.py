t = int(input())
LARGE = 2 << 55
for _ in range(t):
    n = int(input())
    l = list(map(int,input().split()))
    l.append(LARGE)
    
    s = sum(l)
    if s % 2:
        s += 1
        l[-1] += 1
        
    x = 0
    for v in l:
        x ^= v

    assert(s < 2 * x)

    diff = 2 * x - s
    print(3)
    print(l[-1], diff//2, diff//2)