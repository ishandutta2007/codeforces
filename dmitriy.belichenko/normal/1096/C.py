from math import gcd
t = int(input())
for i in range(t):
    n = int(input())
    p = gcd(180 , n)
    if(p + n == 180):
        print(360 // p)
    else:
        print(180 // p)