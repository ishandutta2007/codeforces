#include<bits/stdc++.h>
#define N 2500
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
char o[105],s[105];

int t,tot,n,h,l;

struct noo
{
	char s[105];
	bool operator < (const noo & a)const 
	{
		int l;
		int l1=strlen(s);
		int l2=strlen((a.s)); 
		if(l1>l2)l=l2; else l=l1;
		for(int i=0; i<l; ++i)
		{
			if(s[i]<a.s[i])return 1;
			if(s[i]>a.s[i])return 0;
		}
		if(l1<=l2)
		return 0;
		return 1;
	}
};

map<noo,int>m;
char uu[105][105];
struct node
{
    
    int st[N],u,qn,tt,tot,op[N],oo[N][10]; 
    node()
    {
    	qn=0;
    	memset(oo,0,sizeof(oo));
    	memset(op,0,sizeof(op)); //da xiao     xiaoda
		tot=1,tt=1,op[1]=1;
	} 
    
	inline void insert()
	{
		u=1; 
		for(int i=l; i; --i)
		{
			if(!oo[u][s[i]-48])oo[u][s[i]-48]=++tot;
			if(!op[u])++tt;
			op[u]=1;
			u=oo[u][s[i]-48];
		}
	}

	void dfs(int p)
	{
		if(!op[p])
		{
			for(int i=qn; i; --i)
			printf("%c",st[i]); 
			printf(" ");
		}
		for(int i=0; i<=9; ++i)if(oo[p][i])
		{
			st[++qn]=i+48;
			dfs(oo[p][i]);
			--qn;
		}
	}
	
	inline void pri()
	{
		dfs(1);
	}
}g[152];

/*

int cmp(char a[],  char b[]) //*b  //b[104]  //O M
{
	int l;
	int l1=strlen(a);
		int l2=strlen(b); 
		if(l1>l2)l=l2; else l=l1;
		for(int i=0; i<l; ++i)
		{
			if(a[i]<b[i])return 1;
			if(a[i]>b[i])return 0;
		}
		if
		return 0;
}

*/

int main()
{

	
	n=read();
	for(int i=1; i<=n; ++i )
	{
		scanf("%s",o); 
		int ooo=strlen(o);
		noo   gg ;
		for(int j=0; j<ooo; ++j)gg.s[j]=o[j];
		gg.s[ooo]='\0';
		
//		if(i==2) //;
//		cerr<< cmp(gg.s,uu[1]) /<<endl;
		
		//cerr throw  re  vout
		
		
//		printf("%d %d\n",m[gg],tot);
		if(!m[gg])
		{
		
		m[gg]=++tot;
//		printf("%d %d\n",m[gg],tot);
	
		
//		t=tot;  
		for(int i=0; i<ooo;++i)uu[tot][i]=o[i];
		uu[tot][ooo]='\0'; 
	}
		t=m[gg];	
		h=read();
		for(int j=1; j<=h; ++j)
		{
			scanf("%s",s+1);
			l=strlen(s+1);
			g[t].insert(); 
		}
	}
//string  //char *  /// []
    //uoj // //\n/ // _
    printf("%d\n",tot);

	for(int i=1; i<=tot; ++i)
	{
		printf("%s ",uu[i]); 
		printf("%d ",g[i].tot-g[i].tt);
		g[i].pri();
		puts("");//printf  \n // 
	}
	
} //%d\n  dierhang kaitou kongge yebeidu