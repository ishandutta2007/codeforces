a,b = list(map(int,input().split()))
x = a//b
if x % 2 == 1:
    print('YES')
else:
    print('NO')