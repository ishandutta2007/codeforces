for _ in range(int(input())):
    n = int(input())
    n = ((n*5) + 1)//2
    if(n<15):
        print(15)
    elif(n%5==0):
        print(n)
    else:
        print(n + (5 - (n%5)))