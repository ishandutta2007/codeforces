a = [0]
cur = 1

while(cur < 10 ** 13):
    x = a[-1]
    a.append(x * 2 + cur)
    cur *= 2

n = int(input())
n -= 1

ans = 0
i = 1
cur = 1
while(n > 0):
    x = n % 2
    n = n // 2
    if(x > 0):
        ans += cur + a[i - 1]
    i += 1
    cur *= 2
    
print(ans)