import sys
import math

MOD = int(1e9 + 7)
line = lambda: map(int, input().split())

def solve():
    n = int(input())
    x = [x for x in line()]
    x.sort()
    p2 = []
    p2.append(1)
    for i in range(1, n):
        p2.append(p2[i - 1] * 2 % MOD)
    ans = 0
    for i in range(n):
        ans += x[i] * (p2[i] - p2[n - i - 1] + MOD)
        ans %= MOD
    print(ans)

def main():
    solve()
    exit(0)

main()