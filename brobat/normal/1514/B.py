for _ in range(int(input())):
    n, k = map(int, input().split())
    print((n**k)%(1000000007))