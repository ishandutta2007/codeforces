n,x=map(int,input().split())
a={1,2}
a.remove(1)
a.remove(2)
for i in range(1,n+1):
    if x%i==0 and x/i<=n:
        a.add(i)
print(len(a))