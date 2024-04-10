#include <iostream>
#include <cstdio>
#include <algorithm> 
#include <map>
#include <vector>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef vector<int> vin;
typedef vector<i64> v64;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
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
#pragma comment(linker, "/STACK:102400000,102400000") 
typedef pair<int,i64> info;
#define p(x) (1ll*(x)*(x)*(x))
v64 a;
map<i64,info> zball;
inline info calc(i64 n){
	if(n<=7)return mk((int)n,n);
	if(zball.count(n))return zball[n];
	int d=upper_bound(a.begin(),a.end(),n)-a.begin()-1;
	info p1=calc(a[d]-1),p2=calc(n%a[d]);
	info &res=zball[n];
	p1.w1+=n/a[d]-1;p1.w2+=(n/a[d]-1)*a[d];
	p2.w1+=n/a[d];p2.w2+=n/a[d]*a[d];
	if ((p1.w1>p2.w1)||((p1.w1==p2.w1)&&(p1.w2>p2.w2))) return res=p1;
		else return res=p2;
}
int main(){
	rep(i,1,100000)a.push_back(p(i));
	i64 n;cin>>n;
	info p=calc(n);
	cout<<p.w1<<' '<<p.w2;
}