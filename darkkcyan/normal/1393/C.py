from sys import stdin
for testcase in range(int(stdin.readline())):
    n = int(stdin.readline())
    cnt = [0] * (n + 10)
    for i in map(int, stdin.readline().split()):
        cnt[i] += 1
        
    cnt.sort(reverse=True)
    i = 0
    while i < n and cnt[i] == cnt[0]:
        i += 1
    
    group = [i - 1] * (cnt[0] - 1)
    
    cur = 0
    for num in cnt[i:]:
        while num > 0:
            num -= 1
            group[cur] += 1
            cur = (cur + 1) % len(group)
    print(min(group))