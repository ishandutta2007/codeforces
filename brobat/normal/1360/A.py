for _ in range(int(input())):
    a, b = map(int, input().split())
    if(a > b):
        temp = a
        a = b
        b = temp
    if((2*a) > b):
        print(4*a*a)
    else:
        print(b*b   )