for testcase in range(int(input())):
    n = int(input())
    n8 = (n + 3) // 4
    print('9' * (n - n8) + '8' * n8)