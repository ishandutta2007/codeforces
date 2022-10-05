MOD = 998244353

def mod_mul(x, y, c = 0):
    return (x * y + c) % MOD

def inv(x):
    return pow(x, MOD - 2, MOD)

t = int(input())
for _ in range(t):
    n = int(input())

    a = list(map(int, input().split()))

    denom = 1

    pre = [0] * n
    for i in range(1, n):
        if a[i] == a[i-1]:
            pre[i] = pre[i - 1]
        else:
            pre[i] = i
        denom = mod_mul(denom, i - pre[i] + 1)
            

    curr = [1] * n
    pref = [i for i in range(n)]

    for i in range(n//2 - 1):
        new = []
        for j in range(n):
            if pre[j] < 2 * (i + 1):
                new.append(0)
                continue
            new.append(mod_mul(pref[pre[j]], pre[j] - 2 * i - 1))

        pref = [0]
        for j in range(n - 1):
            pref.append((pref[-1] + new[j]) % MOD)

        curr = new

        #print(curr, pref)

    print(mod_mul(pref[pre[-1]], inv(denom)))