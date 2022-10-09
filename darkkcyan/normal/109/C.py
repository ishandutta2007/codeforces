from sys import stdin, stdout
import re
from random import randrange
from pprint import PrettyPrinter
pprint = PrettyPrinter(width=55).pprint

def is_lucky(num):
    return re.fullmatch("[47]+", num) is not None

gr = None
def topo_order(u):
    res = [(u, None, None)]
    i = 0
    while i < len(res):
        u, p, _ = res[i]
        i += 1
        for v, c in gr[u]:
            if v != p:
                res.append((v, u, c))
    return reversed(res)

def main():
    global gr
    n = int(stdin.readline())
    # n = 4000
    gr = [[] for i in range(n)]
    for _ in range(n - 1):
        s = stdin.readline().split()
        u, v = int(s[0]) - 1, int(s[1]) - 1
        c = is_lucky(s[-1])
        # u, v = randrange(n), randrange(n)
        # c = randrange(2) == 1
        gr[u].append((v, c))
        gr[v].append((u, c))
    topo = list(topo_order(0))

    tree_size = [1 for i in range(n)]
    for u, p, _ in topo:
        if p is not None:
            tree_size[p] += tree_size[u]

    dp_up, dp_down = [0 for i in range(n)], [0 for i in range(n)]
    for u, p, cost in topo:
        if p is not None:
            dp_up[p] += tree_size[u] if cost else dp_up[u]

    for u, p, cost in reversed(topo):
        if p is not None:
            dp_down[u] += tree_size[0] - tree_size[u] if cost else dp_down[p] + dp_up[p] - dp_up[u]

    ans = sum(((u + v) * (u + v - 1) for u, v in zip(dp_up, dp_down)))
    print(ans)


if __name__ == "__main__":
    main()