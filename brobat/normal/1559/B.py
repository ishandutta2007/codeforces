for _ in range(int(input())):
    n = int(input())
    s = input()
    arr = []
    q = 0
    for i in range(n):
        arr.append(s[i])
        if(s[i]=='?'):
            q+=1
    if(q==n):
        for i in range(n):
            if(i%2):
                arr[i] = 'B'
            else:
                arr[i] = 'R'
    for i in range(n-1):
        if(arr[i+1]=='?'):
            if(arr[i]=='B'):
                arr[i+1] = 'R'
            elif(arr[i]=='R'):
                arr[i+1] = 'B'
    for i in range(n-1, 0, -1):
        if(arr[i-1]=='?'):
            if(arr[i]=='B'):
                arr[i-1] = 'R'
            elif(arr[i]=='R'):
                arr[i-1] = 'B'
    for i in range(n):
        print(arr[i], end='')
    print()