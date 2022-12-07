import math

def pf(n):
    grr = set()
    while(n%2==0):
        grr.add(2)
        n = n/2
    
    for i in range(3,int(math.sqrt(n))+1,2):
        while (n%i==0):
            grr.add(i)
            n = n/i

    if(int(n)==1):
        return grr
    else:
        grr.add(int(n))

    return grr

def isPrime(n) :
 
    # Corner cases
    if (n <= 1) :
        return False
    if (n <= 3) :
        return True
 
    # This is checked so that we can skip
    # middle five numbers in below loop
    if (n % 2 == 0 or n % 3 == 0) :
        return False
 
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
 
    return True

N = int(input())
n = N
grr = pf(n)

arr = []
for i in range(N):
    arr.append(i+1)

for i in grr:
    for j in range(i-1, N, i):
        arr[j] = 1

count = 1

for i in arr:
    if(i!=1):
        count += 1

if(isPrime(N)):
    count -= 1
    arr[N-2] = 1

if(N==2):
    count += 1

product = 1
for i in arr:
    product *= i
    product %= N

if(product!=1):
    arr[product-1] = 1
    count -= 1

# print(arr)
print(count)
print(1, end= ' ')
for i in arr:
    if(i!=1):
        print(i, end = ' ')