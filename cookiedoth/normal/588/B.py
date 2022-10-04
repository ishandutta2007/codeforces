import math
n = int(input())
m = n
m = math.sqrt(m)
m = math.floor(m)
i = 2
x = 1
while i<=m:
    if (n % i*i)==0:
        while (n % i)==0:
            n = n//i
        n = n*i
        m = n
        m = math.sqrt(m)
        m = math.floor(m)
    i = i+1
print(n)