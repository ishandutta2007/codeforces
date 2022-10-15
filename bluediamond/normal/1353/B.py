R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:n,k=R();print(sum(map(max,sorted(R()),sorted(R())[:-1-k:-1]+[0]*n)))