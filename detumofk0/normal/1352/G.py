t = int(input())

while t > 0:
    t = t - 1
    n = int(input()) 

    if n < 4:
        print(-1)
        continue

    ans = []
    i = 2 - n % 2
    while i <= n:
        ans.append(i)
        i = i + 2

    ans.append(n - 3)
    ans.append(n - 1)    

    j = n - 5
    while j >= 1:
        ans.append(j)
        j = j - 2
    
    print(*ans)