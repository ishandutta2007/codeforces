import sys
input = sys.stdin.readline

n = int(input())
l = [[0] * n for i in range(n)]
for i in range(n):
    for j in range(1,n):
        l[i][j] = j * 1 << (i + j - 1)
for thing in l:
    print(' '.join(map(str,thing)))

sys.stdout.flush()
q = int(input())

for _ in range(q):
    k = int(input())
    out = ['1 1']
    currX = 0
    currY = 0
    for mov in range(2 * n - 2):
        k -= currX
        if k & 1:
            currX += 1
            k -= 1
        else:
            currY += 1
        k //= 2
        out.append(str(currY + 1)+ ' ' + str(currX + 1))
    print('\n'.join(out))
    sys.stdout.flush()