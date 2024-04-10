for _ in range(int(input())):
    n = int(input())
    arr = list()
    for i in range(n):
        arr.append(input())
    # arr[i][j] --> ith row, jth column
    right = list()
    bottom = list()
    isPossible = True
    if(n==1):
        print("YES")
        continue
    for i in range(n):
        right.append(list())
        bottom.append(list())
        for j in range(n):
            right[i].append(False)
            bottom[i].append(False)
    for i in range(n):
        if(arr[n-1][i]=='1'):
            bottom[n-1][i] = True
        if(arr[i][n-1]=='1'):
            right[i][n-1] = True
    for i in range(n-2, -1, -1):
        for j in range(i, -1, -1):
            if(arr[i][j]=='1'):
                if(bottom[i+1][j] or right[i][j+1]):
                    right[i][j] = True
                    bottom[i][j] = True
                else:
                    isPossible = False
                    break
            if(arr[j][i]=='1'):
                if(bottom[j+1][i] or right[j][i+1]):
                    right[j][i] = True
                    bottom[j][i] = True
                else:
                    isPossible = False
                    break
    if(isPossible):
        print("YES")
    else:
        print("NO")