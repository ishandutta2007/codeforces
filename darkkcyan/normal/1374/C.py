for testcase in range(int(input())):
    n = int(input())
    s = input().strip()
    ans = 0
    sum = 0
    for ch in s:
        if ch == '(':
            sum += 1
        else:
            sum -= 1
        ans = max(ans, -sum)
    print(ans)