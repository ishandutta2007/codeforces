out = []
import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    works = True
    for i in range(min(24,n)):
        for j in range(i + 1):
            if a[i] % (j + 2) != 0:
                #print(i,j)
                break
        else:
            works = False
            break
    if works:
        out.append('YES')
    else:
        out.append('NO')
print('\n'.join(out))