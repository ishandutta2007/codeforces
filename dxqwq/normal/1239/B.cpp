#include<bits/stdc++.h>
#define fp(i,a,b) for(register int i=a,I=b+1;i<I;++i)
#define fd(i,a,b) for(register int i=a,I=b-1;i>I;--i)
#define go(u) for(int i=fi[u],v=e[i].to;i;v=e[i=e[i].nx].to)
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
template<class T>inline bool cmax(T&a,const T&b){return a<b?a=b,1:0;}
template<class T>inline bool cmin(T&a,const T&b){return a>b?a=b,1:0;}
using namespace std;
const int N=3e5+5;
typedef int arr[N];
int n,sL=1,sR=1,Mid,Min,Num,Top,Ans;
arr L,R,fa,stk,Cnt;
char c[N],s[N];
int main(){
	#ifndef ONLINE_JUDGE
		file("s");
	#endif
	scanf("%d\n",&n);gets(c+1);
	fp(i,1,n){
		c[i]=='('?++Top:--Top;
		if(Top<Min)Min=Top,Mid=i;
	}
	if(Top)return puts("0\n1 1"),0;
	fp(i,Mid+1,n)s[i-Mid]=c[i];
	fp(i,1,Mid-1)s[i+n-Mid]=c[i];
	fp(i,1,n)
		if(s[i]=='(')stk[++Top]=++Num,L[Num]=i;
		else R[stk[Top]]=i,fa[stk[Top]]=stk[Top-1],++Cnt[stk[--Top]];
	Ans=Cnt[0];
	fp(i,1,Num)
		if(Cnt[i]+1>Ans&&!fa[i])Ans=Cnt[i]+1,sL=L[i],sR=R[i];
		else if(Cnt[0]+Cnt[i]+1>Ans&&fa[i]&&!fa[fa[i]])Ans=Cnt[0]+Cnt[i]+1,sL=L[i],sR=R[i];
	(sL+=Mid)>n?sL-=n:0,(sR+=Mid)>n?sR-=n:0;
	printf("%d\n%d %d",Ans,sL,sR);
return 0;
}