n = int(input())
dom = []
for _ in range(n):
    dom.append(list(input().strip()))

for d in dom:
    if d[1] == 'W':
        d[1] = 'B'
    elif d[1] == 'B':
        d[1] = 'W'

MOD = 998244353

def modmul(x, y, c = 0):
    return (x * y + c) % MOD

def inv(x):
    return pow(x, MOD - 2, MOD)

MAX = 10 ** 6

fact = [1]
for i in range(1, MAX):
    fact.append(modmul(i, fact[i-1]))

invfact = [1] * (MAX)
invfact[MAX - 1] = inv(fact[MAX - 1])
for i in range(MAX - 2, -1, -1):
    invfact[i] = modmul(i + 1, invfact[i+1])

def comb(x, y):
    return modmul(fact[x], modmul(invfact[y], invfact[x - y]))

out = 0

wL = 0
wR = 0
qL = 0
qR = 0

for d in dom:
    if d[0] == 'W':
        wL += 1
    if d[1] == 'W':
        wR += 1
    if d[0] == "?":
        qL += 1
    if d[1] == '?':
        qR += 1

for i in range(n + 1):
    if wL <= i <= wL + qL and wR <= i <= wR + qR:
        out += modmul(comb(qL, i - wL),comb(qR, i - wR))

bad = 1
for d in dom:
    if d == ['W','B']:
        bad = 0
    elif d == ['B','W']:
        bad = 0
    elif d == ['?','?']:
        bad = modmul(2, bad)

out -= bad

if not any('B' in d for d in dom):
    out += 1
if not any('W' in d for d in dom):
    out += 1

print(out % MOD)