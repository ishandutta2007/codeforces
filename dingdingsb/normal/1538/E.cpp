#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
int count(string now){
	int cnt=0;
	for(int i=0;i+3<now.size();i++)
		if(now.substr(i,4)=="haha")
			cnt++;
	return cnt;
}
struct node{
	ll cnt;
	string pre,suf;
	node(){
		cnt=0;pre=suf="";
	}
	node(string s){
		cnt=count(s);
		int len=min(3,(int)s.size());
		pre=s.substr(0,len);
		suf=s.substr(s.size()-len,len);
	}
	friend node operator+(const node a,const node b){
		node res;
		if(a.suf.size()<3||b.pre.size()<3){
			res=node(a.suf+b.pre);
			res.cnt+=a.cnt+b.cnt;
			return res;
		}
		res.pre=a.pre;
		res.suf=b.suf;
		res.cnt=a.cnt+b.cnt+count(a.suf+b.pre);
		return res;
	}
};
int t,n;
signed main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		map<string,node>hh;
		ll ans=0;
		while(n--){
			string x,op,y,z;
			cin>>x>>op;
			if(op==":="){
				cin>>y;
				hh[x]=node(y);
			}else{
				cin>>y>>op>>z;
				hh[x]=hh[y]+hh[z];
			}
			ans=hh[x].cnt;
		}
		write(ans);putchar('\n');
	}
}