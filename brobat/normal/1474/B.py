import math

def isPrime(n):
    if (n<=1):
        return False
    if (n<=3):
        return True
    if(n%2==0 or n%3==0):
        return False
    for i in range(5,int(math.sqrt(n)+1),6):
        if(n%i==0 or n%(i+2)==0):
            return False
    return True

def nextPrime(n):
    if n<=1:
        return 2
    prime = n
    found = False
    while (not found):
        prime += 1
        if(isPrime(prime)==True):
            found = True
    return prime


T = int(input())
for _ in range(T):
    d = int(input())
    val1 = nextPrime(d)
    val2 = nextPrime(val1+d-1)
    print(val1*val2)