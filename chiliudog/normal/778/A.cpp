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
const int maxn=200005;
char s[maxn],t[maxn];
int del[maxn],n,m;
char cur[maxn];
inline bool check(int x){
	int tot=0;
	rep(i,1,n)if(del[i]>x)cur[++tot]=s[i];
	int now=0;
	rep(i,1,tot){
		if(now==m)continue;
		if(cur[i]==t[now+1])now++;
	}
	return now==m;
}
int main(){
    scanf("%s",s+1);n=strlen(s+1);
    scanf("%s",t+1);m=strlen(t+1);
    rep(i,1,n){
    	int x;read(x);del[x]=i;
    }
    int l=1,r=n,ans=0;
    while(l<=r){
    	int md=(l+r)>>1;
    	if(check(md)){
    		ans=md;l=md+1;
    	}else
    		r=md-1;
    }cout<<ans;
    return 0;
}