for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    a = 0
    b = 0
    c = 0
    for i in range(n):
        if(arr[i]%3==0):
            a += 1
        elif(arr[i]%3==1):
            b += 1
        else:
            c += 1
    ans = 0
    n = n/3
    for _ in range(3):
        if(a>n):
            b += a-n
            ans += a-n
            a = n
        elif(b>n):
            c += b-n
            ans += b-n
            b = n
        elif(c>n):
            a += c-n
            ans += c-n
            c = n
    print(int(ans))