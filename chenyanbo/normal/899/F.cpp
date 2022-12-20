#include<bits/stdc++.h>
#define N 215000
#define lo(a) (a&(-(a)))
//low lowbit    x   x x-1  //abs //fabs ab _
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int aa[N],o[N],st[N],l,r,n,m,to; //= //const
set<int>op[150];
char s[N],c;
set<int>::iterator it;

inline void add(int p)
{//2
	for(int i=p; i<=n; i+=lo(i)) ++aa[i];
}

inline int qu(int p)
{
	int u=0;
	for(int i=p; i; i-=lo(i)) u+=aa[i];
	return u;//
}
//splay //  a[150] 
inline int fid(int p)
{
	int l=1,r=n,m,ans;  //l //mid //_ //no _..  //l_
   	while(l<=r)
	{
		m=(l+r)>>1;
		if(m-qu(m)>p)r=m-1;
		else if(m-qu(m)<p)l=m+1;
		else ans=m,r=m-1; //;  //no yes ,}    ={}   (node){} //uoj //ans //_    // no ans
	}
	return ans;
}

int main()
{
	n=read(); m=read();
	scanf("%s",s+1);
	for(int i=1; i<=n; ++i)op[s[i]].insert(i);
	while(m--)
	{
		l=read(); r=read();
		l=fid(l);
		r=fid(r);
		scanf("%c",&c);
		
		it=op[c].lower_bound(l); 
		to=0; 
		while(it!=op[c].end())
		{
			if(*it>r)break;
			st[++to]=*it;
			++it;
		}  
		for(int i=1; i<=to; ++i)
		{
			add(st[i]);//_
		    op[c].erase(st[i]);
		}
    }
    for(int i=1; i<=122; ++i)if(!op[i].empty())  
    {
    	for(set<int>::iterator it=op[i].begin(); it!=op[i].end(); ++it)
    	o[*it]=i; 
	}
	for(int i=1; i<=n; ++i)if(o[i])
		printf("%c",o[i]);

}