t = int(input())
for _ in range(t):
    c, d = map(int, input().split())
    if (c + d) % 2 == 1:
        print(-1)
    elif c == 0 and d == 0:
        print(0)
    elif c == d:
        print(1)
    else:
        print(2)