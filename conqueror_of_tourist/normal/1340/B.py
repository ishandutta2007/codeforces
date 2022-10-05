digits = ["1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"]
counts = [s.count('1') for s in digits]
bits = [int(s,2) for s in digits]
n, k = map(int,input().split())
poss = [[] for i in range(n)]
for i in range(n):
    s = input()
    count = s.count('1')
    bit = int(s,2)

    for d in range(9,-1,-1):
        if bit & bits[d] == bit:
            poss[i].append((d,counts[d] - count))



dp = [[False]*(k+1) for i in range(n+1)]
dp[0][0] = True
for i in range(n):  
    allowed = poss[n-i-1]
    for j in range(k + 1):
        if dp[i][j]:
            for _, c in allowed:
                if j + c <= k:
                    dp[i + 1][j + c] = True

out = []
if dp[n][k]:
    curr = k
    for i in range(n):
        #print(i, curr)
        for v, c in poss[i]:
            if curr - c >= 0 and dp[n - i - 1][curr - c]:
                #print(v)    
                out.append(v)
                curr -= c
                break
        assert(dp[n - i - 1][curr])
    print(''.join(map(str,out)))
else:
    print(-1)