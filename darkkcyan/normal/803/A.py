from sys import stdin, exit
n, k = map(int, stdin.readline().split())
if k > n * n:
    print(-1)
    exit(0)

a = [[0 for i in range(n)] for i in range(n)]

for i in range(n):
    for f in range(n):
        if a[i][f] == 1:
            continue
        if k == 0: 
            break
        if i == f or k > 1:
            a[i][f], a[f][i] = 1, 1
            k -= 1 + int(i != f)

print('\n'.join(' '.join(map(str, i)) for i in a))