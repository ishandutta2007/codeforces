import sys
input = sys.stdin.readline

n = int(input())
x = []
y = []
out = 0
for _ in range(n):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

for l in (x,y):

    sos = 0
    tot = 0
    count = 0
    for v in l:
        out += count * v * v + sos - 2 * v * tot
        sos += v * v
        tot += v
        count += 1
print(out)