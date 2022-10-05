t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(lambda x: int(x)- 1, input().split()))
    out = []

    ll = [(l[i], i) for i in range(n)]
    ll.sort()

    swap = (-1,-1)
    for i in range(n - 1):
        if ll[i][0] == ll[i + 1][0]:
            swap = (ll[i][1],ll[i+1][1])

    newl = [0]*n
    for i in range(n):
        newl[ll[i][1]] = i

    l = newl

    swapN = 0
    for i in range(n):
        for j in range(i + 1, n):
            if l[i] > l[j]:
                swapN += 1

    #print(l)
    if swapN & 1:
        l[swap[0]],l[swap[1]] = l[swap[1]],l[swap[0]]
    #print(l)

    def shift(i):
        out.append(i + 1)
        l[i],l[i+1],l[i+2] = l[i+2],l[i],l[i+1]

    works = True
    done = False

    while not done:
    
        for i in range(n):
            if l[i] != i:
                break
        else:
            done = True

        if done:
            break

        for find in range(i + 1, n):
            if l[find] == i:
                break

        while find - i >= 2:
            find -= 2
            shift(find)

        if find - i == 1:
            if find <= n - 2:
                shift(find - 1)
                shift(find - 1)
            else:
                works = False
                break

    #print(l)
    if works:
        print(len(out))
        print(' '.join(map(str,out)))
    else:
        print(-1)
    #print('---')