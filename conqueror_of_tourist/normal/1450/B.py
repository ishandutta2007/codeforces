import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    l = []

    for i in range(n):
        x, y = map(int, input().split())
        l.append((x,y))

    for x, y in l:
        for x2, y2 in l:
            if abs(x - x2) + abs(y - y2) > k:
                break
        else:
            print(1)
            break
    else:
        print(-1)