nTest = int(input())

while nTest > 0:
    nTest = nTest - 1
    n = int(input())

    ans = []
    curPow = int(1)

    while n > 0:
        temp = curPow * (n % int(10))
        if(temp > 0): 
            ans.append(temp)
        n = n // 10
        curPow = curPow * 10
    
    ans.reverse()
    print(len(ans))
    print(*ans)