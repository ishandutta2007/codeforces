factor = []
MOD = 1000000007

n, x = map(int, input().split())
fa = 2
import math
sq = int(math.sqrt(n))
while n != 1:
    if fa > sq+1:
        break
    if n % fa:
        fa += 1
        continue
    cnt = 0
    while n % fa == 0:
        cnt += 1
        n //= fa
    factor.append((fa, cnt))
    fa += 1

if n != 1:
    factor.append((n, 1))

ans = 1
for pr, ti in factor:
    X, ex = x, 0
    while X:
        ex += X // pr
        X //= pr
    ans = (ans * pow(pr, ex, MOD)) % MOD

print(ans)