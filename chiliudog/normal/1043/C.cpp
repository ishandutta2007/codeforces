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
string s;
const int maxn=1005;
int ans[maxn];
int main(){
	cin>>s;
	int n=s.length();
	int sta=0;
	// 0 A
	// 1 A
	rep(i,1,n-1){
		if(s[i]=='a'){
			if(sta==0){
				ans[i-1]=1;
				sta=1;
			}else{
				ans[i-1]=0;
				sta=1;
			}
		}else{
			if(sta==0){
				sta=0;
			}else{
				ans[i-1]=1;
				sta=0;
			}
		}
	}ans[n-1]=sta;
	rep(i,0,n-1)printf("%d ",ans[i]);
	return 0;
}