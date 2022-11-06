t = int(input())

while t > 0:
    t = t - 1

    n = int(input())
    a = list(map(int, input().split()))

    b = a.copy()
    b.sort()

    pointer = []
    total = []
    for i in range(1, n):
        pointer.append(i - 1)
        total.append(a[i] + a[i - 1])


    ans = 0
    for i in range(n):
        flag = 0
        for j in range(n - 1):
            while pointer[j] > 0 and total[j] < b[i]:
                pointer[j] = pointer[j] - 1
                total[j] = total[j] + a[pointer[j]]
            if total[j] == b[i]:
                flag = 1
        ans = ans + flag
    
    print(ans)