for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    x, y, min_x, min_y, max_x, max_y = 0, 0, 0, 0, 0, 0
    ans_x, ans_y = 0, 0
    for i in range(len(s)):
        if(max_x - min_x >= m or max_y - min_y >= n):
            break
        ans_x = abs(min_x) + 1
        ans_y = abs(min_y) + 1
        if(s[i]=='R'):
            x += 1
            max_x = max(x, max_x)
        if(s[i]=='L'):
            x -= 1
            min_x = min(x, min_x)
        if(s[i]=='D'):
            y += 1
            max_y = max(y, max_y)
        if(s[i]=='U'):
            y -= 1
            min_y = min(y, min_y)
        # print(x, y)
    if(max_x - min_x >= m or max_y - min_y >= n):
        pass
    else:
        ans_x = abs(min_x) + 1
        ans_y = abs(min_y) + 1
    print(f"{ans_y} {ans_x}")