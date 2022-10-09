x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

points = [(x0, y0)]

def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])

while len(points) < 100:
    points.append((points[-1][0] * ax + bx, points[-1][1] * ay + by))

while len(points) > 0 and  dist(points[-1], (xs, ys)) > t:
    points.pop()

ans = 0
for beg in range(len(points)):
    for left in range(beg + 1):
        for right in range(beg, len(points)):
            to_beg = dist((xs, ys), points[beg])
            min_side = min(dist(points[beg], points[left]), dist(points[beg], points[right]))
            seg_length = dist(points[left], points[right])
            if to_beg + min_side + seg_length <= t:
                ans = max(ans, right - left + 1)
print(ans)