for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    e = 0
    o = 0
    for i in arr:
        if(i%2==0):
            e += 1
        else:
            o += 1
    arr.sort()
    pos = False
    for i in range(n-1):
        if(arr[i+1]-arr[i]==1):
            pos = True
            break
    if(o%2==0 and e%2==0):
        print("YES")
        continue
    if(o%2==1 and e%2==1):
        if(pos):
            print("YES")
            continue
    print("NO")