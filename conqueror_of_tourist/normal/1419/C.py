for _ in range(int(input())):
    n, x = map(int, input().split())
    l = list(map(int, input().split()))
    if sum(l) == n*x:
        if min(l) == x:
            print(0)
        else:
            print(1)
    else:
        if any(v == x for v in l):
            print(1)
        else:
            print(2)