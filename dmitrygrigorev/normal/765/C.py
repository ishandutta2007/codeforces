k, a, b = list(map(int, input().split()))
number = a // k + b // k
if number == 0 or (a < k and b % k != 0) or (b < k and a % k != 0):
    print(-1)
else:
    print(number)