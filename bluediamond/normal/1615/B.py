def cnt(limit, bit):
    full = (limit + 1) // (1 << (bit + 1))
    rem = (limit + 1) % (1 << (bit + 1))
    return full * (1 << bit) + max(rem - (1 << bit), 0)

def solve(l, r):
    sol = 0
    for bit in range(30):
        sol = max(sol, cnt(r, bit) - cnt(l - 1, bit))

    return r - l + 1 - sol

for tc in range(int(input())):
    l, r = map(int, input().split())
    print(solve(l, r))