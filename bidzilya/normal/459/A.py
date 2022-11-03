x1, y1, x2, y2 = map(int, raw_input().split(' '))

d = max(abs(x1 - x2), abs(y1 - y2))
if x1 == x2:
    print x1 + d, y1, x1 + d, y2
elif y1 == y2:
    print x1, y1 + d, x2, y1 + d
else:
    if abs(x1 - x2) != abs(y1 - y2):
        print -1
        exit()
    if x1 > x2:
        x1, y1, x2, y2 = x2, y2, x1, y1
    if y1 > y2:
        print x1 + d, y1, x1, y1 - d
    else:
        print x1 + d, y1, x1, y1 + d