#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<cassert>
#include<queue>
#include<cmath>
#include<queue>
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
const int maxn=100005;
char s1[maxn],s2[maxn];
int n;
int cnt1=0,cnt0=0,all1=0,all0=0;
int main(){
	read(n);
	scanf("%s",s1+1);scanf("%s",s2+1);
	rep(i,1,n){
		if(s2[i]=='0'&&s1[i]=='1')cnt1++;
		if(s2[i]=='0'&&s1[i]=='0')cnt0++;
		if(s1[i]=='1')all1++;
		if(s1[i]=='0')all0++;
	}
	i64 ans=0;
	ans+=1ll*cnt0*all1+1ll*cnt1*all0-1ll*cnt1*cnt0;
	cout<<ans<<endl;
	return 0;
}