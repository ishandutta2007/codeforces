n = int(input()) + 1
l = list(map(int, input().split())) + [0]
out = 0

q = []
for v in l:
    if v == 0:
        dp = []
        n = len(q)
        for i in range(n):
            curr = q[i] + i
            smol = q[i]
            for j in range(i - 1, -1, -1):
                smol = min(q[j], smol)
                diff = q[i] - smol
                curr = min(curr, diff + dp[j] + i - j - 1)
            dp.append(curr)
                
        real = [n - i + dp[i] - 1 for i in range(n)] + [n]
        out += min(real)
        q = []
    else:
        q.append(v)
print(out)