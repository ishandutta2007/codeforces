#include<algorithm>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<ctime>
#include<vector>

#define For(a,b,c) for (int a=b;a<c;i++)
#define ForD(a,b,c) for (int a=b;a>c;a--)
#define lowbit(x) (x&-x)
#define D double
#define LL long long
#define M(x,y) map<x,y>
#define V(x) vector<x>
#define S(x) set<x>
#define _N putchar('\n');
#define _K putchar(' ');

const int inf=0x7fffffff;
const int maxn=300100;
const int maxm=300100;
using namespace std;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int abs(int a){return a>0?a:-a;}

template<typename T>inline void read(T &x){
	char t=getchar();LL a=1;
	while ((!isdigit(t))&&t!='-')t=getchar();
	if (t=='-')a=-1,t=getchar();
	for (x=t^48,t=getchar();isdigit(t);t=getchar())x=x*10+(t^48);
	x=a*x;
}
template<typename T>void R(T &a){read(a);}
template<typename T>void R(T &a,T &b){read(a);read(b);}
template<typename T>void R(T &a,T &b,T &c){read(a);read(b);read(c);}
template<typename T>void R(T &a,T &b,T &c,T &d){read(a);read(b);read(c);read(d);}
template<typename T>void write(T x){
    if (x<0)putchar('-'),x=-x;
    if (x>9)write(x/10);
    putchar(x%10+'0');
}
template<typename T>void writeln(T x){
    if (x<0)putchar('-'),x=-x;
    if (x>9)write(x/10);
    putchar(x%10+'0');_N
}
template<typename T>void W(T a){writeln(a);}
template<typename T>void W(T a,T b){write(a);_K;writeln(b);}
template<typename T>void W(T a,T b,T c){write(a);_K;write(b);_K;writeln(c);}
template<typename T>void W(T a,T b,T c,T d){write(a);_K;write(b);_K;write(c);_K;writeln(d);}

int exgcd(LL a,LL b,LL &x,LL &y){
	if (b==0){x=1;y=0;return a;}
		else {LL t=exgcd(b,a%b,y,x);y-=a/b*x;return t;}
}

/*
//  
int cnt,head[maxn];
struct Edge{
	int to,nxt,cost;
}edge[maxn];
void addE(int a,int b,int c){
	edge[++cnt]=(Edge){b,head[a],c};head[a]=cnt;
}*/
/*
//  
int cnt,head[maxn];
struct Edge{
	int to,nxt;
}edge[maxn];
void addE(int a,int b){
	edge[++cnt]=(Edge){b,head[a]};head[a]=cnt;
}*/

/*
//
int s[maxn];
void add(int x,int y){for (;x<=n;x+=lowbit(x))s[x]+=y;}
int ask(int x){for(int ans=0;x;x-=lowbit(x))ans+=s[x];return ans;}
//add(i,p[i]);ask(r)-ask(l-1);
//add(i,p[i]-p[i-1]);add(l,x);add(r+1,-x);ask(x);
*/

/*
// 
const int size=301000;
bool isp[size];
int plist[size],phi[size];
int top=0;
void getprime(){
	isp[1]=1;
	for (int i=2;i<=size;i++){
		if (!isp[i])plist[++top]=i,phi[i]=i-1;
		for (int j=1;j<=top&&i*plist[j]<=size;j++){
			isp[i*plist[j]]=0;
			if (i%plist[j]==0){phi[i*plist[j]]=phi[i]*prime[j];break;}
			phi[i*plist[j]]=phi[i]*phi[prime[j]];
		}
	}
}
*/ 

/*=================================================================================*/

int n,m,ans,mino=inf,mini;
int s[3];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	R(n);
	if (n<2){
		puts("0");
		return 0;
	}
	For(i,0,3){
		R(s[i]);
		if (mino>s[i])mino=s[i],mini=i;
	}
	if (mini==1&&mini==0)ans=(n-1)*mino;
		else{
			ans=min(s[0],s[1])+(n-2)*mino;
		}
	W(ans);
	return 0;
}