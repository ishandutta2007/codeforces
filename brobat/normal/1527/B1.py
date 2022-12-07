for _ in range(int(input())):
    n = int(input())
    s = input()
    z = 0
    for i in range(n):
        if(s[i]=="0"):
            z += 1
    if(z%2==0):
        print("BOB")
    elif(z==1):
        print("BOB")
    else:
        print("ALICE")