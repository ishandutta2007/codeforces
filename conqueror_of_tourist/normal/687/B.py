def gcd(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x 

n, k = map(int, input().split())
l = map(int, input().split())

lcm = 1

for v in l:
    lcm = lcm * v // gcd(lcm, v)
    lcm = gcd(lcm, k)

if k == lcm:
    print('Yes')
else:
    print('No')