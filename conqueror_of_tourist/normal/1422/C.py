s=input();M=10**9+7;o=u=v=0;n=len(s)
for i in range(n):c=int(s[i]);u+=v;v=(10*v+c)%M;o+=pow(10,n-i-1,M)*((i*i+i)//2*c+u)
print(o%M)