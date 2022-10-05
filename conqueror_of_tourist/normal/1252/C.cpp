t = int(input())

for test in range(t):
    input()
    max1 = max(map(int,input().split()))
    max2 = max(map(int,input().split()))
    if max1 > max2:
        print('YES')
    else:
        print('NO')