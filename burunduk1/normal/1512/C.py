for cycle in range(int(input())):
    zeroes,ones = [int(x) for x in input().split()]
    s = list(input())
    n = len(s)
    fail = False
    # print(f"\ntest: s = {''.join(s)}")
    for i in range(n):
        if s[i] != s[n - i - 1]:
            # print(f"i = {i}")
            fail |= (s[i] != '?' and s[n - i - 1] != '?')
            x = chr(ord(s[i]) + ord(s[n - i - 1]) - ord('?'))
            s[i], s[n - i - 1] = x, x
    zeroes -= s.count('0')
    ones -= s.count('1')
    for i in range(n):
        if s[i] == '?' and n - i - 1 != i:
            if zeroes >= 2:
                s[i], s[n - i - 1] = '0', '0'
                zeroes -= 2
            else:
                s[i], s[n - i - 1] = '1', '1'
                ones -= 2
    if n % 2 == 1 and s[n // 2] == '?':
        if zeroes >= 1:
            s[n // 2] = '0'
            zeroes -= 1
        else:
            s[n // 2] = '1'
            ones -= 1
    # print(fail, zeroes, ones, s)
    if fail or zeroes != 0 or ones != 0:
        print(-1)
    else:
        print(''.join(s))