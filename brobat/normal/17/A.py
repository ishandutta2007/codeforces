n,k = map(int,input().split())
arr = [0]*(n+1)
primes = []
for i in range(2,n+1):
    if(arr[i]==0):
        arr[i] = 1
        primes.append(i)
        for j in range(i,n+1,i):
            arr[j] = 1
# print(primes)
sums = []
for i in range(len(primes)-1):
    sums.append(primes[i]+primes[i+1]+1)
# print(sums)
ans = set(primes).intersection(set(sums))
if len(ans)>=k:
    print("YES")
else:
    print("NO")