from math import *
for test in range(int(input())):
    a = input().strip();
    b = input().strip()
    g = gcd(len(a), len(b))
    x = a * (len(b) // g)
    y = b * (len(a) // g)
    
    if x != y:
        print("-1")
    else:
        print(x)