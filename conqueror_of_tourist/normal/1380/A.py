T = int(input())
for _ in range(T):
    n = int(input())
    l = list(map(int, input().split()))
    for i in range(n - 1):
        if l[i] < l[i + 1]:
            break
    k = -1
    for j in range(i + 1, n - 1):
        if l[j] > l[j + 1]:
            k = j + 1
            break
    if k != -1:
        print('YES')
        print(i+1,1+j,k+1)
    else:
        print('NO')