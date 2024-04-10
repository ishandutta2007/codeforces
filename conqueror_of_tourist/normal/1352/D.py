t = int(input())
for _ in range(t):
    a = 0
    b = 0
    n = int(input())
    As = list(map(int,input().split()))
    left = 0
    right = n - 1

    a += As[0]
    left = 1
    min = As[0]

    curr = 0
    turn = False
    count = 1
    while left <= right:
        if turn:
            a += As[left]
            curr += As[left]
            left += 1
        else:
            b += As[right]
            curr += As[right]
            right -= 1
        if curr > min:
            count += 1
            min = curr
            curr = 0
            turn = not turn
    if curr != 0:
        count += 1
    print(count, a, b)