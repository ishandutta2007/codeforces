import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    n, x = map(int, input().split())
    l = list(map(int,input().split()))
    l.sort(reverse = True)
    best = 0
    s = 0
    for i in range(n):
        s += l[i]
        if s >= x * (i+1):
            best = i + 1
        else:
            break
    print(best)