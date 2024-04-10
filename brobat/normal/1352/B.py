for _ in range(int(input())):
    n, k = map(int, input().split())
    if(k%2==0):
        if(n%2==1):
            print("NO")
            continue
           
        if(k > n):
            print("NO")
            continue
        print("YES")
        for i in range(k - 1):
            print(1, end=' ')
        print(n - (k-1))
    else:
        if(n%2==0):
            if(2*k > n):
                print("NO")
                continue
            print("YES")
            for i in range(k - 1):
                print(2, end=' ')
            print(n - 2*(k-1))
        else:
            if(k > n):
                print("NO")
                continue
            print("YES")
            for i in range(k-1):
                print(1, end=' ')
            print(n - k + 1)