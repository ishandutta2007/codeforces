def make_good(s, c):
    if len(s) == 1:
        return int(s[0] != c)
    
    mid = len(s) // 2
    
    ans = len(s)
    for x, y, z, t in [(0, mid, mid, len(s)), (mid, len(s), 0, mid)]:
        cur_ans = 0
        for i in s[x:y]:
            cur_ans += int(i != c)
        cur_ans += make_good(s[z:t], chr(ord(c) + 1))
        ans = min(ans, cur_ans)
    return ans
    
for testcase in range(int(input())):
    n = int(input())
    s = input().strip()
    print(make_good(s, 'a'))