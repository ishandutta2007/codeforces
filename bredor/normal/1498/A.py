# 228
import math
def dn(n):
    nn=0
    for i in n:
        nn+=int(i)
    return nn
for _ in range(int(input())):
    n=input()
 
 
    while math.gcd(int(n),dn(n))==1:
        n=str(int(n)+1)
    print(n)