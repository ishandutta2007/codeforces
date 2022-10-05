import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    x -= 1

    degree = [0] * n
    edges = [(0,0)]*(n-1)
    for i in range(n - 1):
        u, v = map(int, input().split())
        edges[i] = (u-1,v-1)
        degree[u-1] += 1
        degree[v-1] += 1

    if degree[x] == 1 or degree[x] == 0:
        print('Ayush')
    else:
        print('Ashish' if n % 2 else 'Ayush')