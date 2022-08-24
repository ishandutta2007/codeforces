def test(n):
    maximum = int(n ** 0.5) + 3
    for i in range(2, min(maximum, n)):
        if n % i == 0:
            return False
    return True   


n = int(input())
if n % 2 == 0:
    if n == 2:
        print(1)
    else:    
        print(2)
else:
    if test(n) == True:
        print(1)
    elif test(n - 2) == True:
        print(2)
    else:
        print(3)