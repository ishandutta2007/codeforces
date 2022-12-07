for _ in range(int(input())):
    n = int(input())
    if(n%2==0):
        for i in range(n):
            if(i%2==0):
                print(i+2, end=' ')
            else:
                print(i, end=' ')
    else:
        for i in range(n):
            if(i==0):
                print(2, end=' ')
            elif(i==1):
                print(3, end=' ')
            elif(i==2):
                print(1, end=' ')
            elif(i%2==0):
                print(i, end=' ')
            else:
                print(i+2, end=' ')
    print()