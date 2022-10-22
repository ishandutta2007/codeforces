te = int(input())
while te > 0:
    te -= 1
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    i = 0
    cnt = [0] * (n+1)
    for x in a:
        while x > n:
            x //= 2
        cnt[x] += 1

    failed = False
    for i in range(n, 0, -1):
        if not cnt[i]:
            failed = True
            break
        t = cnt[i] - 1
        if t:
            cnt[i//2] += t

    if failed:
        print("NO")
    else:
        print("YES")