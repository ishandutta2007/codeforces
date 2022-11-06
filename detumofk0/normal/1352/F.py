t = int(input())

while t > 0:
    t = t - 1
    x, y, z = map(int, input().split())

    if x > 0 and y == 0 and z == 0:
        print('0' * (x + 1))
        continue

    if z > 0 and x == 0 and y == 0:
        print('1' * (z + 1))
        continue
    
    ans = '1' * (z + 1) + '0' * (x + 1)
    for i in range(1, y):
        if ans[-1] == '1':
            ans = ans + '0'
        else:
            ans = ans + '1'
    
    print(ans)