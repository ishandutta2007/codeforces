te = int(input())
while te > 0:
    te -= 1
    n = int(input())
    a = map(int, input().split())
    sm = sum(a)
    if sm == n:
        print(0)
    elif sm < n:
        print(1)
    else:
        print(sm - n)