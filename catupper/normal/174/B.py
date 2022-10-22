a=raw_input()
t=a.split('.')
k=map(len,t)
l=len(t)-1
if l<1:
    print "NO"
    exit()
if(9>k[0]>0 and 0<k[-1]<4):
    for x in range(len(k)):
        if x==0 or x==len(k)-1:continue
        if 1<k[x]<12:continue
        else:
            print "NO"
            exit()
else:
    print "NO"
    exit()

print "YES"
for x in range(l):
    if x==0 and l==1:
        print a
    elif x==0 and l!=1:
        print t[x]+"."+t[x+1][:min(3,len(t[x+1])-1)]        
    elif x==l-1:
        print t[x][min(3,len(t[x])-1):]+"."+t[x+1]
    else:
        print t[x][min(3,len(t[x])-1):]+"."+t[x+1][:min(3,len(t[x+1])-1)]