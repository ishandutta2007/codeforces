q = int(input())
while( q > 0):
    n = int(input())
    dx = n * n - 4 * n
    if(dx < 0):
        print('N')
        q = q - 1
        continue
    sdx = dx ** 0.5
    x1 = n + sdx
    x2 = n - sdx
    x1 /= 2
    x2 /= 2
    print('Y' , x1 , x2)
    q = q - 1