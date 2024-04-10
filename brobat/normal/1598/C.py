for _ in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    s = sum(arr)
    arr.sort()
    ans = 0
    l = dict()
    for i in range(n):
        try:
            l[arr[i]] += 1
        except:
            l[arr[i]] = 1
    special = 0
    for i in range(n):
        # n * (arr[i] + arr[j]) = 2 * sum
        if(2*s%n != 0):
            continue
        x = 2*s//n
        if(x == 2*arr[i]):
            # ans += (l[arr[i]] * (l[arr[i]] - 1))//2
            special = l[arr[i]]
        else:
            try:
                ans += l[x - arr[i]]
            except:
                ans += 0
    ans = ans//2
    ans += (special * (special - 1))//2
    print(ans)