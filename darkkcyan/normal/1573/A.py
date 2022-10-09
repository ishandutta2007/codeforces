for testcase in range(int(input())):
    n = int(input())
    s = input().strip()
    ans = ord(s[-1]) - ord('0')
    for i in s[:n - 1]:
        if i != '0':
            ans += 1 + ord(i) - ord('0')
    print(ans)