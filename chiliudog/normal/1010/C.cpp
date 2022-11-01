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
int n,k,a[maxn];
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
vector<int> ans;
set<int> st;
int main(){
	read(n);read(k);
	rep(i,1,n){
		read(a[i]);
	}
	int res=a[1];
	rep(i,1,n)res=gcd(res,a[i]);
	res=gcd(res,k);
	if(res%k==0){
		puts("1\n0");
		return 0;
	}else{
		int x=res;
		x%=k;
		// cout<<res<<endl;
		while(!st.count(x)){
			ans.pb(x);
			st.insert(x);
			x=(x+res)%k;
		}
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<endl;
		for(int x:ans){
			printf("%d ",x);
		}
	}
	return 0;
}