#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long vv[50];
const int MO = 998244353;
#define dd 29
inline int  ksm(int p, long long k)
{
	vv[0]=p; 
	for(int i=1; i<=29; ++i)vv[i]=vv[i-1]*vv[i-1]%MO;
	long long s=1;  
	for(int i=dd; i>=0; --i)if(1<<i<=k){
		k-=1<<i;
		s=s*vv[i]%MO; 
	}
	return s;
}

long long s,n,m,a[2005][2005],b[2005][2005];
char ss[2050];
map<int,int>mp; 
int main()
{
	n=read(); m=read();
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",ss+1);  
		for(int j=1; j<=m; ++j)a[i][j]=ss[j]-'a'+1;
	}
	
	for(int i=1; i<=m; ++i)
	{
		scanf("%s",ss+1);
		for(int j=1; j<=n; ++j)b[i][j]=ss[j]-96;
	}
	
	for(int i=1; i<=m; ++i)
	for(int j=1; j<=m; ++j){
		s+=a[i][j]*ksm(29,m*m-(i-1)*m-j+1)%MO; 
		s%=MO; 
	}
	
	mp[s]=1; 
	
	for(int i=m+1; i<=n; ++i){
		for(int j=1; j<=m; ++j)
		{
		    s+=a[i-m][j]*(MO-ksm(29,m*m-j+1));
		    s%=MO;
		}
		s=s*ksm(29,m)%MO;
		for(int j=1; j<=m; ++j)
		{
	        s+=a[i][j]*ksm(29,m-j+1);
	        s%=MO;
	    }
		mp[s]=i-m+1;
	} 
	
	s=0;
	for(int i=1; i<=m; ++i)
	for(int j=1; j<=m; ++j){
		s+=b[i][j]*ksm(29,m*m-(i-1)*m-j+1)%MO;
		s%=MO; 
	}
	
	if(mp[s]){
		printf("%d %d\n",mp[s],1);
		return 0;
	}
	
	for(int j=m+1; j<=n; ++j){
		for(int i=1; i<=m; ++i)
		{
		    s+=b[i][j-m]*(MO-ksm(29ll,m*(m-i+1)));
		    s%=MO;
		}
		
		s=s*29%MO;
		for(int i=1; i<=m; ++i)
		{
	        s+=b[i][j]*ksm(29,m*(m-i)+1); 
	        s%=MO;
	    }
				
		if(mp[s]){
			printf("%d %d\n",mp[s],j-m+1);
			exit(0); 
		}
	}	
}
/*
2 1
a
b
ba


3 2
ab
cd
ef
gcd
hef
*/