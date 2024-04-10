t = int(input())
for _ in range(t):
    a,b,c= map(int, input().split())
    if (a + b + c)% 9 == 0 and min(a,b,c) * 9 >= (a+b+c):
        print('YES')
    else:
        print('NO')