P=lambda:map(int,input().split())
_,k=P()
print(sum(x<=5-k for x in P())//3)