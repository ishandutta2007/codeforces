import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    p = [-1] * n
    for i in range(n):
        p[a[i] - 1] = b[i] - 1

    visited = [False] * n
    cyc = 0
    for i in range(n):
        if not visited[i]:
            cyc += 1
            curr = i
            visited[i] = True
            while p[curr] != i:
                curr = p[curr]
                visited[curr] = True
    print(pow(2, cyc, 10 ** 9 + 7))