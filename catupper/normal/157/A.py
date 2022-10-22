n=input()

table=[]

def sumco(x):
    res=0
    for i in range(n):
        res+=table[i][x]        
    return res
    
def sumci(x):
    return sum(table[x])
    
def how(x,y):
    return sumco(x)>sumci(y)
    
for x in range(n):
    table+=[map(int,raw_input().split())]

res=0
for x in range(n):
    for y in range(n):
        res+=how(x,y)

print res