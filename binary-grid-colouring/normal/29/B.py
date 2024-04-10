l, d, v, g, r = map(int, input().split())
x = (d / v) % (g + r)
if x < g:
    print(l / v)
else:
    print(d / v + abs(x - (g + r)) + ((l - d) / v))