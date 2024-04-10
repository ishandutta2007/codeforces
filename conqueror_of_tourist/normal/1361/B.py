import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7

t = int(input())
for _ in range(t):
    n, p = map(int, input().split())
    l = list(map(int, input().split()))
    if p == 1:
        print(n % 2)
    else:
        l.sort(reverse = True)
        curr = l[0]
        out = 0
        real = True

        for v in l:
            if v < curr:
                diff = curr - v
                if 10 ** (7/diff) < p and out > 0:
                    real = False
                out *= pow(p, diff, MOD)
                if out > 10 ** 7:
                    real = False
                out %= MOD

                curr = v
            if out > 0 or not real:
                out -= 1
            else:
                out += 1
            out %= MOD

        out *= pow(p, curr, MOD)
        print(out % MOD)