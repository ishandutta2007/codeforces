def func():
    ans = 0
    n = input()
    d = len(n)
    for i in range(1, d+1):
        x = 0
        y = 0
        x = 10**i
        y = (x-1)//9 
        if(i!=d):
            ans += (x//y)
        else:
            ans += (int(n)//y)
    if(d==1):
        return ans
    else:
        return (ans-1)



for _ in range(int(input())):
    print(func())