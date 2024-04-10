for testcase in range(int(input())):
    n = int(input())
    cnt = [[0] * 2 for i in range(2)]
    for i, v in enumerate(map(int, input().split())):
        cnt[i % 2][v % 2] += 1
    if cnt[0][1] != cnt[1][0]:
        print(-1)
    else:
        print(cnt[1][0])