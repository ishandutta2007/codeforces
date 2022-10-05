t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    if a <= b:
        print(b)
    else:
        each = c - d
        if each <= 0:
            print(-1)
        else:
            need = (a - b + each - 1)//each
            print(b + need * c)