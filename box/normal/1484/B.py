import sys
ifs=list(sys.stdin)[1:]
for n,a in zip(ifs[::2],ifs[1::2]):
    n=int(n)
    a=list(map(int,a.split()))
    if n == 1:
        print(0,flush=False)
        continue
    c=a[1]-a[0]
    m=0
    d=max(a)
    for i in range(1,n):
        if m!=0 and (a[i-1]+c)%m!=a[i]:
            m=-1
            break
        if m==0 and a[i-1]+c!=a[i]:
            m=abs(a[i-1]+c-a[i])
            if m<=d:
                m=-1
                break
    if m!=0 and m != -1:
        print(m,c%m,flush=False)
    else:
        print(m,flush=False)