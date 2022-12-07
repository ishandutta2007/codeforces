for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    o = 0
    e = 0
    for i in arr:
        if(i%2==0):
            o+=1
        else:
            e+=1
    if(o==e):
        print("Yes")
    else:
        print("No")