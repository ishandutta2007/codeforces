def cnt_inv(a):
    ans = 0
    for i in range(len(a)):
        for f in range(i + 1, len(a)):
            if a[f] < a[i]:
                ans += 1
    return ans

for testcase in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    inv = cnt_inv(a)

    sorted_a = list(sorted(a))

    last_eq = -1
    for i in range(n - 1):
        if sorted_a[i] == sorted_a[i + 1]:
            last_eq = i + 1

    # print("last_eq", last_eq) 
    ans = []
    def shift(pos):
        global inv
        inv -= int(a[pos] > a[pos + 1]) + int(a[pos] > a[pos + 2]) + int(a[pos + 1] > a[pos + 2])
        a[pos], a[pos + 1], a[pos + 2] = a[pos + 2], a[pos], a[pos + 1]
        inv += int(a[pos] > a[pos + 1]) + int(a[pos] > a[pos + 2]) + int(a[pos + 1] > a[pos + 2])
        ans.append(pos + 1)

    for i in range(n - 3):
        pos = min(range(i, n), key=lambda x: a[x])
        # print(a, val, pos) 
        while pos > i + 1:
            shift(pos - 2)
            pos -= 2
        if pos == i + 1:
            shift(i)
            shift(i)
        if i == last_eq and inv % 2 == 1:
            shift(i)
            shift(i - 1)

    last_min = min(*a[-3:])
    while a[-3] != last_min:
        shift(n - 3)
    
    if n - 3 == last_eq and inv % 2 == 1:
        shift(n - 3)
        shift(n - 4)
        
    cnt = 0
    while not (a[-3] <= a[-2] <= a[-1]):
        shift(n - 3) 
        cnt += 1
        if cnt > 5:
            break
    if cnt > 5:
        print(-1)
    else:
        print(len(ans))
        print(' '.join(map(str, ans)))