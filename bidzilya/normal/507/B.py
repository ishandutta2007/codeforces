def get_ints():
    return map(int, raw_input().strip().split(' '))

r, x1, y1, x2, y2 = get_ints()
d2 = (x1 - x2) ** 2 + (y1 - y2) ** 2
r2 = r ** 2
k2 = d2 / (4 * r2)
if k2 * 4 * r2 < d2:
    k2 += 1
k = long(k2 ** 0.5)
if k * k < k2:
    k += 1
print k