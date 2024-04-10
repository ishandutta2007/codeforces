n = int(input())
j = int((n ** 0.5) + 1)
q = n
for i in range(2 , j):
    if(n % i == 0):
        #print(i)
        q = min(q , i)
        break
if(q == n):
    print(1)
if(q < n):
    print(1 + (n - q)//2)