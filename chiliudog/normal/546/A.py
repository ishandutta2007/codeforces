k,n,w=map(int,input().split())
print(max(0,((k+w*k)*w)//2-n))