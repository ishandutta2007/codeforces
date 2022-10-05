t = int(input())
MOD = 10 ** 9 + 7
for _ in range(t):
    n, k = map(int, input().split())
    print(pow(n,k,MOD))