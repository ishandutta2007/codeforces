import sys

sys.setrecursionlimit(1500)

cells = [i + j for j in '12345678' for i in 'abcdefgh']
dist = {(c, d) : 100 for c in cells for d in cells}
path = {(c, d) : None for c in cells for d in cells}
for c in cells:
    for i, j in [(1, 2), (2, 1), (-1, 2), (2, -1), (1, -2), (-2, 1), (-1, -2), (-2, -1)]:
        d = chr(ord(c[0]) + i) + chr(ord(c[1]) + j)
        if d in cells:
            dist[(c, d)] = 1
            path[(c, d)] = d
for k in cells:
    for i in cells:
        for j in cells:
            if dist[(i, j)] > dist[(i, k)] + dist[(k, j)]:
                dist[(i, j)] = dist[(i, k)] + dist[(k, j)]
                path[(i, j)] = path[(i, k)]

horses = set()
n = int(input())
ans = []
for _ in range(n):
    horses.add(input())

def move_horse(b, e):
    ans.append('%s-%s' % (b, e))
    horses.remove(b)
    horses.add(e)

def long_move_horse(b, e):
    if b == e:
        return
    c = path[(b, e)]
    if c in horses:
        long_move_horse(c, e)
        if c not in horses:
            move_horse(b, c)
    else:
        move_horse(b, c)
        long_move_horse(c, e)

for c in cells[: n]:
    if c not in horses:
        for d in horses:
            if d not in cells[: n]:
                long_move_horse(d, c)
                break

print(len(ans))
print(*ans, sep = '\n')