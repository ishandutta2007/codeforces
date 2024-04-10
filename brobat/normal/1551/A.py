for _ in range(int(input())):
    n = int(input())
    if(n%3==0):
        print(f"{n//3} {n//3}")
    elif(n%3==1):
        print(f"{n//3 + 1} {n//3}")
    else:
        print(f"{n//3} {n//3 + 1}")