from sys import stdin

def color(x, y):
    return int((x + y) % 2 == 0)

def gen_cells(x, y, k):
    for i in range(x, x + k):
        yield (i, y)
    for i in range(x, x + k, 2):
        yield (i, y + 1)
        yield (i, y - 1)
    yield (x - 1, y)
    yield (x + k, y)

for query in range(int(stdin.readline())):
    b, w = map(int, stdin.readline().split())
    if max(b, w) > 4 + 3 * (min(b, w) - 1):
        print("NO")
        continue
    print("YES")
    x, y = 10**7, 10**7
    if b < w:
        x += 1
    for i, point in zip(range(b + w), gen_cells(x, y, min(b, w) * 2 - 1)):
        print("%d %d" % point)