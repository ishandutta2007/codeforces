BIG = 10 ** 5

primes = [True] * 10 ** 5

primes[0] = False
primes[1] = False
for i in range(2, BIG):
    if primes[i]:
        for j in range(2 * i, BIG, i):
            primes[j] = False

t = int(input())
for _ in range(t):
    n = int(input())
    for p in range(1 + n, BIG):
        if primes[p]:
            break
    for q in range(p + n, BIG):
        if primes[q]:
            break
    print(p * q)