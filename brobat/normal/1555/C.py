for _ in range(int(input())):
    m = int(input())
    arr = list()
    arr.append(list())
    arr.append(list())
    for i in range(2):
        arr[i] = list(map(int, input().split()))
    grr = list()
    grr.append(list())
    grr.append(list())
    grr[0].append(arr[0][0])
    grr[1].append(arr[1][0])
    for i in range(2):
        for j in range(m-1):
            grr[i].append(grr[i][j] + arr[i][j+1])
    # print(grr)
    # Alice can make n decisions. ith decision --> turn is made at position i.
    if(m==1):
        print(0)
        continue
    bob = [-1]*m
    for i in range(m):
        if(i==0):
            bob[i] = grr[0][m-1] - grr[0][0]
        elif(i==m-1):
            bob[i] = grr[1][m-2]
        else:
            bob[i] = max(grr[1][i-1], grr[0][m-1] - grr[0][i])
    print(min(bob))