for s in[*open(0)][2::2]:a=*map(int,s.split()),;n=len(a);t=sum(a);print((sum(x*n>t
for x in a),-1)[t%n>0])