t = int(input())
for i in range(t):
    n = int(input())
    s = 3
    while n % s:
        s *= 2
        s += 1
    print(n//s)