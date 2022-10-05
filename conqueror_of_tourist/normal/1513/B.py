import sys
input = sys.stdin.readline

outL = []

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    good = [True] * n
    allA = a[0]
    for v in a:
        allA &= v
    for i in range(30):
        mask = 1 << i
        if allA & mask == 0:
            for j in range(n):
                if mask & a[j]:
                    good[j] = False
    count_good = 0
    for v in good:
        if v:
            count_good += 1
    out = count_good * (count_good - 1)
    MOD = 10 ** 9 + 7
    for i in range(n - 2):
        out *= (i + 1)
        out %= MOD
    outL.append(out)
print('\n'.join(map(str,outL)))