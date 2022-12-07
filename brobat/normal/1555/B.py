import math
for _ in range(int(input())):
    W, H = map(int, input().split())
    x1, y1, x2, y2 = map(int, input().split())
    w, h = map(int, input().split())
    available_x = W + x1 - x2
    available_y = H + y1 - y2
    # print(available_x, available_y)
    # print(math.sqrt((available_x - w)**2 + (available_y - h)**2))
    z = False
    ans = 1000000000000.0
    if(available_x >= w):
        current_available = max(x1 - 0, W - x2)
        t1 = float(max(0, w - current_available))
        ans = min(ans, t1)
        z = True
    if(available_y >= h):
        current_available = max(y1 - 0, H - y2)
        t2 = float(max(0, h - current_available))
        ans = min(ans, t2)
        z = True
    # print(z)
    if(z):
        print(ans)
    else:
        print(-1)