for test in range(int(input())):
    x1, y1, z1 = map(int, input().split())
    x2, y2, z2 = map(int, input().split())
    
    ans = 0
    
    t = min(z1, y2)
    z1 -= t
    y2 -= t
    ans += 2 * t
    
    t = min(z1, z2)
    z1 -= t
    z2 -= t
    
    t = min(x1, z2)
    x1 -= t
    z2 -= t
    
    t = min(y1, y2)
    y1 -= t
    y2 -= t
    
    t = min(y1, x2)
    y1 -= t
    x2 -= t
    
    t = min(x1, y2)
    x1 -= t
    y2 -= t
    
    t = min(x1, x2)
    x1 -= t
    x2 -= t
    
    t = min(y1, z2)
    ans -= 2 * t
    print(ans)