T =  int(input())

for _ in range(T):
    n = int(input())
    
    ls = [int(i) for i in input().split()]

    ls.sort()

    ans = 0
    for i in ls:
        if i != ls[0]:
            ans = ans + 1

    print(ans)