for _ in range(int(input())):
    n = int(input())
    arr = list()
    for i in range(n):
        arr.append(list(map(int, input().split())))
    pos = False
    for i in range(4):
        for j in range(i + 1, 5):
            if(pos):
                break
            # n[i] + n[j] - n[i and j] = n.
            a = 0
            b = 0
            c = 0
            for k in range(n):
                if(arr[k][i]==1):
                    a += 1
                if(arr[k][j]==1):
                    b += 1
                if(arr[k][i]==1 and arr[k][j]==1):
                    c += 1
            if(a + b - c == n and a >= n//2 and b >= n//2):
                print("YES")
                pos = True
    if(pos == False):
        print("NO")