import sys
input = sys.stdin.readline

MOD = 10 ** 9 + 7
things = [[1] for _ in range(10)]
for i in range(1, 2 * 10 ** 5 + 5):
    for d in range(10):
        if d < 9:
            things[d].append(things[d+1][i-1])
        else:
            new = (things[0][i-1] + things[1][i-1])
            things[d].append(new % MOD)

outL = []
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    out = 0
    while n:
        out += things[n % 10][m]
        n //= 10
        out %= MOD
    outL.append(out)
print('\n'.join(map(str,outL)))