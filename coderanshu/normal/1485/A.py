T = int(input())

for _ in range(T):

    a, b = [int(i) for i in input().split()]

    ans = 1e9

    for i in range(60):

        x, y = b + i, a

        if x == 1:
            continue
        cnt = 0
        while y:
            cnt += 1
            y //= x
        ans = min(ans,cnt+i)
    print(ans)