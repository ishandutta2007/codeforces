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
int hp1,atk1,def1;
int hp2,atk2,def2;
int h,a,d;
int main(){
    // judge();
	read(hp1);read(atk1);read(def1);
	read(hp2);read(atk2);read(def2);
	read(h);read(a);read(d);
	int ans=1e9;
	rep(hp,hp1,5000)rep(atk,atk1,200)rep(def,def1,100){
		int cost=h*(hp-hp1)+a*(atk-atk1)+d*(def-def1);
		if(cost>ans)continue;
		if(atk<=def2)continue;
		int r=hp2/(atk-def2)+(hp2%(atk-def2)!=0);
		if(hp-(atk2-def)*r<=0)continue;
		ans=min(ans,cost);
	}cout<<ans;
    return 0;
}