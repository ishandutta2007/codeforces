a,b=map(int,raw_input().split())

defnition=[ 0 for x in range(a)]

hannninn=[[] for x in range(a)]
tensi=[[] for x in range(a)]

for x in range(a):
    t=input()
    if(t<0):
        tensi[-t-1]+=[x]
        defnition[x]=-1
    else:
        hannninn[t-1]+=[x]
        defnition[x]=-3


shan=sum(map(len,hannninn))    
num=0
for x in range(a):
    if(shan-len(hannninn[x])+len(tensi[x])==a-b):
        #uso===1  honto===3
        num+=1
        for k in hannninn[x]:defnition[k]=1
        for k in tensi[x]:defnition[k]=3

for x in range(a):
    if(defnition[x]==-1):
        print 'Truth'
    if(defnition[x]==-3):
        print 'Lie'
    if(defnition[x]==1):
        if(num==1):
            print 'Truth'
        else:
            print 'Not defined'
    if(defnition[x]==3):
        if(num==1):
            print 'Lie'
        else:
            print 'Not defined'