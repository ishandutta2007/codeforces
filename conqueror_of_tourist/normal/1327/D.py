T = int(input())
for _ in range(T):
    n = int(input())
    perm = list(map(lambda x: int(x) - 1, input().split()))
    color = list(map(int, input().split()))

    SMALL = n

    unseen = set(range(n))
    while unseen:
        start = unseen.pop()
        l = [start]
        nex = start
        while perm[nex] != start:
            nex = perm[nex]
            l.append(nex)
            unseen.remove(nex)

        size = len(l)
        factors = []

        curr = 1
        while curr * curr <= size:
            if size % curr == 0:
                factors.append(curr)
                factors.append(size//curr)
            curr += 1

        for f in factors:
            works = [True] * f
            for i in range(size):
                if color[l[i]] != color[l[i % f]]:
                    works[i % f] = False

            for b in works:
                if b:
                    SMALL = min(SMALL, f)
                    break

    print(SMALL)