// Problem: CF474E Pillars
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF474E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
#define int long long
typedef long long ll;
const int N=1e5+100;
int n,d;
int a[N],dp[N],lst[N];
vector<int>num;
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
pair<int,int> mx[N<<2];
void upd(int x,int l,int r,int pos,pair<int,int> val){
	chkmx(mx[x],val);
	if(l==r){
		return;
	}
	if(pos<=mid)upd(lc,l,mid,pos,val);
	else upd(rc,mid+1,r,pos,val);
}
pair<int,int> qry(int x,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return mx[x];
	if(r<ql||qr<l)return {0,0};
	return max(qry(lc,l,mid,ql,qr),qry(rc,mid+1,r,ql,qr));
}
signed main(){
	read(n,d);
	for(int i=1;i<=n;i++)
		read(a[i]),num.pb(a[i]);
	sort(num.begin(),num.end());
	num.resize(unique(num.begin(),num.end())-num.begin());
	for(int i=1;i<=n;i++){
		int l=upper_bound(num.begin(),num.end(),a[i]-d)-num.begin()-1;
		int x=lower_bound(num.begin(),num.end(),a[i])-num.begin();
		int r=lower_bound(num.begin(),num.end(),a[i]+d)-num.begin();
		auto kk=max(qry(1,0,num.size()-1,0,l),qry(1,0,num.size()-1,r,num.size()-1));
		dp[i]=kk.first+1;lst[i]=kk.second;
		upd(1,0,num.size()-1,x,{dp[i],i});
	}
	write(mx[1].first);putchar('\n');
	vector<int>ans;int x=mx[1].second;
	while(x){
		ans.pb(x);x=lst[x];
	}
	reverse(ans.begin(),ans.end());
	for(auto x:ans)write(x),putchar(' ');
}