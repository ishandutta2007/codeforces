import sys
input = sys.stdin.readline
n, k = map(int, input().split())

ands= []
orz = []
for i in range(3):
    print('and',i+1,(i+1)%3+1)
    print('or',i+1,(i+1)%3+1)
sys.stdout.flush()

for i in range(3):
    ands.append(int(input()))
    orz.append(int(input()))

vals = [0] * n
for bit in range(31):
    mask = 1 << bit
    for i in range(3):
        if ands[i] & mask or ands[i-1] & mask or (orz[i] & mask and orz[i-1] & mask and not (orz[i-2] & mask)):
            vals[i] += mask

for i in range(3, n):
    print('and',i+1,1)
    print('or',i+1,1)
    sys.stdout.flush()

    i1 = int(input())
    i2 = int(input())
    vals[i] = i1 + i2 - vals[0]

vals.sort()
print('finish',vals[k-1])