#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
char s[20];
int a[20],pw[20];
map<int,int> ans;
map<i64,int> cnt;
inline int trans(int *a,int n){
	int res=0;
	rep(i,1,n){
		res*=3;res+=(a[i]+1);
	}return res;
}
inline void add(){
	int n=strlen(s+1);
	rep(i,1,n)a[i]=(s[i]-'0')%2;
	int x=trans(a,n);
	rep(i,n,18){
		ans[x]++;
		x+=pw[i]*1;
	}x=trans(a,n);
	rep(i,1,n){
		if(a[i]==1)break;
		x-=pw[n-i]*(a[i]+1);
		ans[x]++;
	}
}inline void del(){
	int n=strlen(s+1);
	rep(i,1,n)a[i]=(s[i]-'0')%2;
	int x=trans(a,n);
	rep(i,n,18){
		ans[x]--;
		x+=pw[i]*1;
	}x=trans(a,n);
	rep(i,1,n){
		if(a[i]==1)break;
		x-=pw[n-i]*(a[i]+1);
		ans[x]--;
	}
}
int main(){
	pw[0]=1;
	rep(i,1,18)pw[i]=3*pw[i-1];
	int T;read(T);
	while(T--){
		char ch=getchar();
		while(ch!='+'&&ch!='-'&&ch!='?')ch=getchar();
		scanf("%s",s+1);
		if(ch=='+')add();
		if(ch=='-')del();
		if(ch=='?'){
			int n=strlen(s+1);
			rep(i,1,n)a[i]=s[i]-'0';
			int x=trans(a,n);
			printf("%d\n",ans[x]);
		}
	}
	return 0;
}