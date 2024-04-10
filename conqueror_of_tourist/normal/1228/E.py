n, k = list(map(int,input().split()))

M = 10 ** 9 + 7

def binom(a,b):
    num = 1
    for i in range(a,a-b,-1):
        num = (num*i)%M

    denom = 1
    for i in range(1,b+1):
        denom = (denom*i)%M

    return (num * pow(denom,M-2,M))

binomMem = [0] * (251 * 300)
for i in range(n+1):
    for j in range(i+1):
        binomMem[300 * i + j] = ((binom(i,j)) * pow((k-1),i-j,M))%M


count = [0]*(n+1)
count[0] = 1

for _ in range(n):
    new = [0]*(n+1)

    for i in range(n+1):
        curr = count[i]
        new[i] -= pow(k - 1, n, M) * curr
        curr *= pow(k,i,M)
        curr %= M

        for add in range(n + 1 - i):
            new[i + add] += (curr * binomMem[300 * (n - i) + add])
            new[i + add] %= M
    count = new

print(count[n])