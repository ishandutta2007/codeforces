n,m,kitten=map(int, input().split())
x=[input() for i in range(0,n)]
print(sum(sum(e[i]=='Y' for e in x)>=kitten for i in range(0,m)))