for _ in range(int(input())):
    n, a, b = map(int, input().split())
    s = input()
    arr = []
    for i in range(n):
        arr.append(int(s[i]))
    # print(arr)
    i = 0
    t = n
    while(i<(t-1)):
        if(arr[i]==arr[i+1]):
            arr.pop(i+1)
            t-=1
        else:
            i+=1
    k = len(arr)
    if(b>=0):
        print((a+b)*n)
    else:
        k = (k+2)//2
        print(a*n + b*k)