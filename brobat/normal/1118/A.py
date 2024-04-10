for _ in range(int(input())):
    n, a, b = map(int, input().split())
    if(a*2 < b):
        print(n*a)
    else:
        print(b*(n//2) + a*(n%2))