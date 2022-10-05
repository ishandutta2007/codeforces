for _ in [0]*int(input()):
 n=int(input());o=0;c=1
 while n >= 0:
  n-=c*(c+1)//2;o+=1;c=2*c+1
 print(o-1)