for testcase in range(int(input())):
    n = int(input())
    cnt2, cnt3 = 0, 0
    while n % 2 == 0:
        n //= 2
        cnt2 += 1
    while n % 3 == 0:
        n //= 3
        cnt3 += 1

    if n > 1 or cnt3 < cnt2:
        print(-1)
        continue

    print(2 * cnt3 - cnt2)