for testcase in range(int(input())):
    n = int(input())
    s = input().strip()
    if n < 7:
        print("no")
        continue
    
    ans = ""
    for i in range(n - 6):
        assignable = True
        for u, v in zip(s[i:], "abacaba"):
            if u not in v + '?':
                assignable = False
                break
        if not assignable:
            continue
        
        t = s[:i] + "abacaba" + s[i + 7:]
        cnt = 0
        for pos in range(n - 6):
            if t[pos:pos+7] == "abacaba":
                cnt += 1
        if cnt == 1:
            ans = t.replace('?', 'd')
            break
    if len(ans) == 0:
        print("no")
    else:
        print("yes")
        print(ans)