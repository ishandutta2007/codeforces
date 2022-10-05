n = int(input())
out = []

MOD = 998244353 

for i in range(1, n + 1):
    if i == n:
        out.append(10)
    else:
        nex = 2 * 9 * pow(10, n - i - 1, MOD) * 10
        if i < n - 1:
            nex += (n - 1 - i) * 9 * 9 * pow(10, n - i - 2, MOD) * 10
        out.append(nex % MOD)
        

print(' '.join(map(str,out)))
#print(sum((i + 1) * out[i] for i in range(n)))
#print(n * pow(10, n, MOD))