#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
int x,t;
long long l,r,nn,g,o,n,m,h;
int main()
{
	t=read();
	while(t--){
		x=read();
		/*
		for(int i=1; i<=1000; ++i)
		for(int j=1; j<=i; ++j)
		{
			if(i*i-((i-1)/(j+j-1)+1)*((i-1)/(j+j-1)+1)==x){
				cout<<i<<' '<<j<<endl;goto lll;
			}
		}*/
				
		if(!x){
			puts("1 1");
			continue;
		}
		
		h=sqrt(x+0.01);
		for(int i=1; i<=h; ++i)if(!(x%i)){
			g=x/i;
			if((g^i)&1)continue;
			n=(g+i)/2;
			o=(g-i)/2;
			
			
			if(!o)continue;
			
			if(o==1){
				cout<<n<<' '<<n<<endl; 
				goto lll;
			}
			
			r=n/(o-1)+1;
			l=n/o;
			
			for(int i=l; i<=r; ++i)
			{
				if(n/i!=o)continue;
			    if(n<m)continue;
		    	cout<<n<<' '<<i<<endl;
		    	goto lll;
		    }
			
			/*
			--o;
			nn=n-1;
			l=nn/(o+1)+1;
			r=nn/o;
            for(int i=l; i<=r; ++i)if(i&1)
			{
				m=(i+1)/2;
			    if(n*n-((n-1)/(m+m-1)+1)*((n-1)/(m+m-1)+1)!=x)continue;
			    if(n<m)continue;
		    	cout<<n<<' '<<m<<endl;
		    	goto lll;
		    }*/
		}
		puts("-1");
		lll:;
	}
}