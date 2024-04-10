t = int(input())
for _ in range(t):
    n = int(input())
    for i in range(2, 10 ** 5):
        if n % i == 0:
            print(n//i,n - n // i)
            break
    else:
        print(1,n-1)