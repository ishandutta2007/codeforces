from sys import stdin
for testcase in range(int(stdin.readline())):
    n, k = map(int, stdin.readline().split())
    has_ans = True
    picked = set()
    for num in map(int, stdin.readline().split()):
        i = 0
        while (num > 0) and has_ans:
            while num % k == 0:
                num //= k
                i += 1
            if i in picked:
                has_ans = False
                break
            picked.add(i)
            num -= 1
        if not has_ans:
            break
    print('YES' if has_ans else 'NO')