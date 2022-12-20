#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read()
{
	int ret=0; char c=getchar();
	while (c>57 || c<48)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 100001
int ans,a1,a2,f[100001][3],f_[100001][3],n,c,d,t1,t2,p[N],b[N];
char s[2];
struct node
{
	int b,p;
}o[N],h[N];

bool cmp(const node&a,const node&b) //const   chongzai
{
	if(a.b!=b.b)
	return a.b>b.b;
	return a.p<b.p;
}

int main()
{
	n=read(),c=read(),d=read();
	for(int i=1; i<=n; ++i)
	{
	    b[i]=read(),p[i]=read(),scanf("%s",s);
	    //s=="C"  //strcmp  //strncmp
	    if(*s=='C')o[++t1].b=b[i],o[t1].p=p[i];
	    else h[++t2].b=b[i],h[t2].p=p[i];
	}
	sort(o+1,o+t1+1,cmp);
	sort(h+1,h+t2+1,cmp); 
	for(int i=1; i<=t1; ++i)
	{
		if(o[i].p<=c)
		{
			a1=o[i].b;
			break;
		}
	}
	for(int i=1; i<=t2; ++i)
	{
		if(h[i].p<=d)
		{
			a2=h[i].b;
			break; 
		}
	}
/*	if(a1==0 && a2==0) 
	{ 
	} 
else	ans=a1+a2; */
if(a1>0 && a2>0)ans=a1+a2;
	for(int i=1; i<=t1; ++i)
	{
		int k=o[i].b,l=o[i].p;
		if(k>=f[l][1])
		{
			f[l][2]=f[l][1];
			f_[l][2]=f_[l][1];
			f[l][1]=k;
			f_[l][1]=i;
		}else
		if(k>f[l][2])
		{
			f[l][2]=k;
			f_[l][2]=i;
		}
	}
	for(int i=2; i<=100000; ++i)
	{
		if(f[i-1][1]>=f[i][1])
		{
			f[i][2]=f[i][1];
			f_[i][2]=f_[i][1];
			f[i][1]=f[i-1][1];
			f_[i][1]=f_[i-1][1];
		}else
		if(f[i-1][1]>f[i][2])
		{
			f[i][2]=f[i-1][1];
			f_[i][2]=f_[i-1][1];
		}
		
		if(f[i-1][2]>=f[i][1])
		{
			f[i][2]=f[i][1];f_[i][2]=f_[i][1];
			f[i][1]=f[i-1][2]; f_[i][1]=f_[i-1][2];
		}else
		if(f[i-1][2]>f[i][2])
		{
			f[i][2]=f[i-1][2]; f_[i][2]=f_[i-1][2];
		}
	} 
	for(int i=1; i<=c/2; ++i)
	{
		if(f_[i][1]==f_[c-i][1] && f[i][1]&&f[c-i][2] &&f_[i][1]!=f_[c-i][2])ans=max(ans,f[i][1]+f[c-i][2]);
		else if(f_[i][1]!=f_[c-i][1]&&f[i][1]&&f[c-i][1])ans=max(ans,f[i][1]+f[c-i][1]);
	}  //begin() end()  r..    //&&

	memset(f,0,sizeof(f));
	memset(f_,0,sizeof f_);  //?  //pianyiliang   //&   ++it it++ +=1s +=3  -= -- //
	for(int i=1; i<=t2; ++i)
	{
		int k=h[i].b,l=h[i].p;
		if(k>=f[l][1])
		{
			f[l][2]=f[l][1];
			f_[l][2]=f_[l][1];
			f[l][1]=k;
			f_[l][1]=i;
		}else
		if(k>f[l][2])
		{
			f[l][2]=k;
			f_[l][2]=i;
		}
	}
	for(int i=2; i<=100000; ++i)
	{
		if(f[i-1][1]>=f[i][1])
		{
			f[i][2]=f[i][1];
			f_[i][2]=f_[i][1];
			f[i][1]=f[i-1][1];
			f_[i][1]=f_[i-1][1];
		}else
		if(f[i-1][1]>f[i][2])
		{
			f[i][2]=f[i-1][1];
			f_[i][2]=f_[i-1][1];
		}
		
		if(f[i-1][2]>=f[i][1])
		{
			f[i][2]=f[i][1];f_[i][2]=f_[i][1];
			f[i][1]=f[i-1][2]; f_[i][1]=f_[i-1][2];
		}else
		if(f[i-1][2]>f[i][2])
		{
			f[i][2]=f[i-1][2]; f_[i][2]=f_[i-1][2];
		}
	}
	for(int i=1; i<=d/2; ++i)
	{
		if(f_[i][1]==f_[d-i][1] && f[i][1] && f[d-i][2] &&f_[i][1]!=f_[d-i][2] )ans=max(ans,f[i][1]+f[d-i][2]);
		else if(f_[i][1]!=f_[d-i][1]&&f[i][1]&&f[d-i][1])ans=max(ans,f[i][1]+f[d-i][1]);
	}
	printf("%d\n",ans) ;
}//1e9  //1e+9