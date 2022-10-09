def day_needed(w, cnt):
    if w <= 0:
        return 0
    return 1 + day_needed(w - cnt * 2, cnt * 2)

for testcase in range(int(input())):
    n = int(input()) - 1
    nday = day_needed(n, 1)

    # print(n + 1, '====') 
    print(nday)

    cnt = 1
    for i in range(nday):
        l, r = 0, cnt
        while l < r:
            mid = (l + r) // 2
            if day_needed(n - mid - cnt, cnt + mid) + i + 1 > nday:
                l = mid + 1
            else:
                r = mid
        print(l, end=' ')
        cnt += l
        n -= cnt
    print()