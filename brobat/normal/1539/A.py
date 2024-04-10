for _ in range(int(input())):
    n, x, t = map(int, input().split())
    r = t//x
    if(n<r):
        print(n*(n-1)//2)
    else:
        print((r*(r-1)//2) + ((n-r)*r))