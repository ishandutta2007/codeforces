nTest = int(input())

for iTest in range(nTest):
    n, k = map(int, input().split())

    if(n < k):
        print('NO')
        continue

    if n % 2 == 1:
        if k % 2 == 0:
            print('NO')
        else:
            print("YES")
            print("{}{}".format('1 ' * (k - 1), n - (k - 1)))
    else:
        if k % 2 == 0:
            print("YES")
            print("{}{}".format('1 ' * (k - 1), n - (k - 1)))
        else:
            if n < 2 * k:
                print('NO')
            else:
                print("YES")
                print("{}{}".format('2 ' * (k - 1), n - 2 * (k - 1)))