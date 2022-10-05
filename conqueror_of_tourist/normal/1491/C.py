import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    S = list(map(int, input().split()))
    todo = [0] * n
    out = 0
    for i in range(n):
        need = S[i] - 1
        smol = todo[i]
        act = max(smol, need)
        out += (act - smol)
        for j in range(2, S[i] + 1):
            if (i + j) >= n:
                break
            todo[i + j] += 1
        if i != n - 1:
            todo[i + 1] += act - need
    print(out)