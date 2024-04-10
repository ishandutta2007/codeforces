pts = []
pts.append(tuple(map(int, input().split())))

pts.append(tuple(map(int, input().split())))

pts.append(tuple(map(int, input().split())))

pts.sort()

if pts[0][1] > pts[2][1]:
    pts = pts[::-1]
    
assert pts[0][1] <= pts[2][1]

ol = []

def cout(a, b, c, d):
    if (a, b) == (c, d):
        return
    ol.append((a,b,c,d))

if pts[1][1] <= pts[0][1]:
    cout(pts[0][0], pts[0][1], pts[2][0], pts[0][1])
    cout(pts[2][0], pts[2][1], pts[2][0], pts[0][1])
    cout(pts[1][0], pts[0][1], pts[1][0], pts[1][1])
elif pts[1][1] >= pts[2][1]:
    cout(pts[0][0], pts[0][1], pts[0][0], pts[2][1])
    cout(pts[2][0], pts[2][1], pts[0][0], pts[2][1])
    cout(pts[1][0], pts[2][1], pts[1][0], pts[1][1])
else:
    cout(pts[0][0], pts[0][1], pts[0][0], pts[1][1])
    cout(pts[0][0], pts[1][1], pts[2][0], pts[1][1])
    cout(pts[2][0], pts[2][1], pts[2][0], pts[1][1])
    
print(len(ol))
for a, b, c, d in ol:
    print(a, b, c, d)