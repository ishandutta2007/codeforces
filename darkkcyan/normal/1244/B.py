for testcase in range(int(input())):
    n = int(input())
    s = input().strip()
    ones = list(i for i in range(n) if s[i] == '1')
    if len(ones) == 0:
        print(n)
        continue
    ans = max(n, 2 * (ones[-1] + 1), 2 * (n - ones[0]))
    print(ans)