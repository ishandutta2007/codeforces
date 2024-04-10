for s in[*open(0)][2::2]:a=sorted(map(int,s.split()));b=[y-x for x,y
in zip(a,a[1:])];i=b.index(min(b))+(len(b)>1);print(*a[i:]+a[:i])