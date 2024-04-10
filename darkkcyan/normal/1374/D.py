for testcase in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    if k == 1:
        print(0)
        continue
    if n == 1:
        if a[0] % k != 0:
            print((k - a[0] % k) % k + 1)
        else:
            print(0)
        continue
    a = filter(lambda i: i != 0, sorted(list((k - i % k) % k for i in a), reverse = True))
    v, id = 0, -1
    prev = -1
    cnt = 0
    for i in a:
        if i == prev:
            cnt += 1
        else:
            v, id = max((v, id), (cnt, prev))
            cnt = 1
            prev = i
    v, id = max((v, id), (cnt, prev))
    if id == -1:
        print(0)
    else:
        print((v - 1) * k + id + 1)