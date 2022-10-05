n,w,*vl = list(map(int,input().split(' '))) + list(map(int,input().split(' ')))
vl.sort()
print(3*n*(min(vl[n]/2,vl[0],w/(3*n))))