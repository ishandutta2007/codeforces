import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    a = map(int, input().split())
    diff = 0
    last = next(a)
    for v in a:
        if last != v:
            diff += 1
        last = v
    if k == 1:
        if diff:
            print(-1)
        else:
            print(1)
    else:
        print(max(1,(diff + k - 2)//(k - 1)))