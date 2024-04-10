for testcase in range(int(input())):
    s = input().strip()
    cnt = {'R': 0, 'S': 0, 'P': 0}
    for i in s:
        cnt[i] += 1
    
    _, w = max(zip(cnt.values(), cnt.keys()))
    ans = ({'R': 'P', 'P': 'S', 'S': 'R'})[w] * len(s)
    print(ans)