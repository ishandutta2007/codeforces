a,b,c=map(int,raw_input().split())

x=a*c/100.0
if(x%1!=0):x+=1
print max(0,int(x)-b)