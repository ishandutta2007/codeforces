import sys
input = sys.stdin.readline

n = int(input())
l = map(int, input().split())

tot = sum(l)
extra = (n * (n - 1))//2
smol = (tot - extra) // n

out = [smol + i for i in range(n)]
excess = tot - sum(out)
for i in range(excess):
    out[i] += 1
print(' '.join(map(str,out)))