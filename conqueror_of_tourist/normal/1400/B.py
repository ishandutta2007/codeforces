import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    p, f = map(int, input().split())
    cs, cw = map(int, input().split())
    s, w = map(int, input().split())
    if s > w:
        s, w = w, s
        cs, cw = cw, cs

    best = 0
    
    for i in range(cs + 1):
        if i * s <= p:
            axes = min(cw,(p - i * s)//w)
            rest_sw = min(cs - i, f//s)
            rest_axes = min(cw - axes, (f - rest_sw * s)//w)
            tot = i + axes + rest_sw + rest_axes
            best = max(best, tot)

    print(best)