x0, y0, ax, ay, bx, by = map(int, input().split())
xs, ys, t = map(int, input().split())

x = [x0]
y = [y0]

while x[-1] < 1e20:
    x.append(x[-1] * ax + bx)
    
while y[-1] < 1e20:
    y.append(y[-1] * ay + by)


n = min(len(x), len(y))

def dist(x0, y0, x1, y1):
    return abs(x0-x1) + abs(y0-y1)

ans = 0
for i in range(n):
    for j in range(i, n):
        d = min(dist(xs, ys, x[i], y[i]), dist(xs, ys, x[j], y[j])) + dist(x[i], y[i], x[j], y[j])
        if d <= t:
            ans = max(ans, j - i + 1)

print(ans)