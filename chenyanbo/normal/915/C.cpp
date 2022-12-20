#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

long long h[150],op,a,b,t[150],ss,bb[150],tt;

int main()
{
	cin>> a >>b;
	for(int i=1; i<=19; ++i)
	{
		++t[a%10];
		a/=10;
		ss=i;
		if(!a)break;
	}
	
	for(int i=1; i<=19; ++i)
	{
		bb[i]=b%10;
		b/=10;
		tt=i;
		if(!b)break;
	}
	
	if(ss<tt)
	{
		for(int i=9;i>=0; --i)
		for(int j=1; j<=t[i]; ++j)printf("%c",i+48);
		return 0;
	}
	for(int i=tt; i; --i)
	{
		op=bb[i];
		if(!t[op])
		{
		    while(!t[op])--op;
		    --t[op];
		    printf("%d",op);
		    for(int i=9;i>=0; --i)
		    for(int j=1; j<=t[i]; ++j)printf("%c",i+48);
		    return 0;
		}
		--t[op];
		memcpy(h,t,sizeof(h));
		for(int j=i-1; j; --j)
		{
		    int fl=1;//bool
			for(int ii=bb[j]-1; ii>=0; --ii)if(h[ii]){
			     fl=0; 
				 break;
		    }
		    if(!fl)break;
			if(!h[bb[j]])
			{
				++t[op];
			    --op;
			    while(!t[op])--op;
		        --t[op];
		        printf("%d",op);
		        for(int i=9;i>=0; --i)
		        for(int j=1; j<=t[i]; ++j)printf("%c",i+48);
		        return 0;
			}
			else --h[bb[j]]; 
		}
		printf("%d",op);
	}
}