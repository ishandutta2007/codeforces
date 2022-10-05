import sys
input = sys.stdin.readline
import random


def gcd(x, y):
    if x > y:
        x, y = y, x
        
    while x:
        x, y = y%x, x
    return y

primes = []

sieve = [True] * 800
sieve[0] = False
sieve[1] = False
for i in range(2, 800):
    if sieve[i]:
        primes.append(i)
        for j in range(2 * i, 800, i):
            sieve[j] = False

smolPrimes = primes[:30]
bigPrimes = primes[30:]
random.shuffle(bigPrimes)
primes = smolPrimes + bigPrimes


count = len(primes)

T = int(input())
for _ in range(T):
    curr = 1
    powers = [1] * count

    for iteration in range(22):
        Q = 1
        indUsed = []

        for i in range(count):
            if powers[i] > 0:
                nex = Q * pow(primes[i], powers[i])
                if nex > 10 ** 18:
                    break
                Q = nex
                indUsed.append(i)
            i += 1

        print('?', Q)
        sys.stdout.flush()
        g = int(input())
        for ind in indUsed:
            pp = pow(primes[ind], powers[ind])
            g2 = gcd(pp, g)

            if g2 == pp:
                powers[ind] += 1
                if powers[ind] >= 4:
                    powers[ind] += 2
            else:
                while pp > g2:
                    powers[ind] -= 1
                    pp //= primes[ind]
                curr *= powers[ind] + 1
                powers[ind] = -1
        

    out = curr * 2
    print('!', max(out, 8))
    sys.stdout.flush()