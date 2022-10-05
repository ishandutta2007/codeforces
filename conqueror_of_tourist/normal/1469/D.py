def cd(x,y):
    return (x+y-1)//y

t=int(input())
for _ in range(t):
    out = []
    n = int(input())
    large = n
    for i in range(n-1,1,-1):
        while cd(large,i) in [i,i+1]:
            out.append(str(n)+' '+str(i))
            large = cd(large,i)
        out.append(str(i)+' '+str(n))
    print(len(out))
    print('\n'.join(out))