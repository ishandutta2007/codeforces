n,k=map(int,input().split())
a=list(map(int,input().split()))
print(sum(x>=a[k-1] and x>0 for x in a))