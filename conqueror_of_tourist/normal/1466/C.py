import sys
input = sys.stdin.readline

t = int(input())
outL = []
for _ in range(t):
    s = input().strip()
    n = len(s)
    dp = [n if len(s) > 1 and s[0] == s[1] else 0,1,1,2]
    for j in range(2, len(s)):
        c = s[j]
        
        new = [n + 2]*4

        for i in range(4):
            base = (i % 2)*2
            new[base + 1] = min(new[base + 1], dp[i] + 1)
            if (i % 2 or c != s[j-1]) and (i & 2 or c != s[j-2]):
                new[base] = min(new[base], dp[i])

        dp = new
        #print(dp)
    outL.append(min(dp))
print('\n'.join(map(str,outL)))