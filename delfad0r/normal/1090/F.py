import itertools

v = {}

def make_query(i, j, k):
    print('? %d %d %d' % (i + 1, j + 1, k + 1))
    return int(input())

def solve5(l):
    a = [(i, make_query(*i)) for i in map(tuple, itertools.combinations(l, 3))]
    b = {j : sorted(v for i, v in a if j in i) for j in l}
    h = sorted(l, key = lambda i : b[i])
    get_a = lambda i, j, k : [v for l, v in a if i in l and j in l and k in l][0]
    x = get_a(h[0], h[1], h[2])
    y = get_a(h[0], h[2], h[4])
    z = get_a(h[2], h[3], h[4])
    v[h[0]] = (x + y - z) // 2
    v[h[2]] = (x - y + z) // 2
    v[h[4]] = (-x + y + z) // 2
    v[h[1]] = get_a(h[1], h[2], h[4]) - v[h[4]]
    v[h[3]] = get_a(h[0], h[2], h[3]) - v[h[0]]

n = int(input())
for i in range(0, n - 4, 5):
    solve5(list(range(i, i + 5)))
solve5(list(range(n - 5, n)))

print('!', *(v[i] for i in range(n)), sep = ' ')