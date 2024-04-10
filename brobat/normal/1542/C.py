import math
for _ in range(int(input())):
    n = int(input())
    ans = n
    l = 1
    i = 2
    while(l<=n):
        ans += n//l
        l = i*l//math.gcd(i, l)
        i += 1
    print(ans%(10**9+7))