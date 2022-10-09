for testcase in range(int(input())):
    s = input().strip()
    print(s[0] + s[1:-1:2] + s[-1])