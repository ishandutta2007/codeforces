t = int( input() )
while(t > 0):
    n = int(input())
    for j in range(1,n + 1):
        sum = ("("*(n-j))+("()"*(j))+(")"*(n-j))
        print(sum)
    t -= 1