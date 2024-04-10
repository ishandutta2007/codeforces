#include<bits/stdc++.h>
#define N 100050
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

struct node
{
	//iterator //xianhou
	int s, h ;//= c++11
	bool operator < (const node & a)const{
		if((long long)s*a.h!=(long long)a.s*h)  //v //
		return (long long)s*a.h>(long long)a.s*h;
		return s>a.s; //<
	}
}a[N]; //;


long long p,ss,n,ans,l;
char s[N];
//-
int main()
{
	n=read();
	for(int i=1; i<=n; ++i){
		scanf("%s",s+1);
		l=strlen(s+1); //i i ii
		p=0;
		for(int j=1; j<=l; ++j){
			if(s[j]=='s')++p; else ans+=p;
		}///long long // l l d //_//\n///  //duoge???wenmohangmo//\n _/// / // /
		a[i].s=p; a[i].h=l-p;
	}//cmp < //node  () ()
	sort(a+1,a+n+1);//unique   //m+1  //-o-1 //-O2
	for(int i=1; i<=n; ++i){
		ans+=(long long)ss*a[i].h;
		ss+=a[i].s;
	}
	cout<<ans<<endl;//namespace 0 //int void //wai
}