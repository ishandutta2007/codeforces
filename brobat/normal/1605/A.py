for _ in range(int(input())):
    a, b, c = map(int, input().split())
    s = (a + b + c)%3
    if(s==0):
        print(0)
    else:
        print(1)