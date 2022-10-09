for _ in range(int(input())):
    n = int(input())
    if n // 2 % 2 == 1:
        print('NO')
        continue
    print('YES')
    print(*range(2, n + 1, 2), sep=' ', end=' ')
    print(*range(1, n  // 2, 2), sep=' ', end=' ')
    print(*range(n // 2 + 3, n + 2, 2), sep=' ')