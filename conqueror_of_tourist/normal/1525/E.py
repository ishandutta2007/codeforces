MOD = 998244353 

def inv_f(x):
    return pow(x, MOD - 2, MOD)

inv = [0] * 50
for i in range(1,50):
    inv[i] = inv_f(i)

n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(list(map(int, input().split())))
out = 0
for j in range(m):
    count = [0] * (n + 1)
    for i in range(n):
        count[board[i][j] - 1] += 1
    p = 0
    tot = n
    for i in range(n):
        tot -= count[~i]
        pp = (tot * inv[n - i]) % MOD
        p = (p + (1 - p) * pp) % MOD
    out += p
    out %= MOD
print(out)