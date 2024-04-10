#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,m,a[MAXN],b[MAXN],c[MAXN];
ll s[MAXN];
int l[MAXN],r[MAXN];
int tag1[MAXN],tag2[MAXN];
vector<int>occ1[MAXN],occ2[MAXN];
struct comp{
	bool operator()(const int& a,const int& b){
		if(tag1[a]!=tag1[b])return tag1[a]>tag1[b];
		if(tag2[a]!=tag2[b])return tag2[a]>tag2[b];
		return a>b;
	}
};
set<int,comp>S;
set<int>pos;
void check(){
	rep(i,1,n)if(s[i]){
		cout<<"NO\n";return;
	}
	cout<<"YES\n";
}
void upd(int l,int r){
	while(pos.size()){
		auto it=pos.lower_bound(l);
		if(it==pos.end())break;
		int p=*it;
		if(p>r)break;
		s[p]=0;
		for(auto num:occ1[p]){
			S.erase(num);
			tag1[num]=1;
			S.insert(num);
		}
		for(auto num:occ2[p]){
			S.erase(num);
			tag2[num]=1;
			S.insert(num);
		}
		pos.erase(p);
	}
}
void solve(){
	cin>>n>>m;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)cin>>b[i],c[i]=a[i]-b[i],s[i]=s[i-1]+c[i];
	rep(i,1,n)occ1[i].clear(),occ2[i].clear();
	S.clear();pos.clear();
	rep(i,0,n)pos.insert(i);
	rep(i,1,m){
		cin>>l[i]>>r[i];
		occ1[l[i]-1].push_back(i);
		occ2[r[i]].push_back(i);
		tag1[i]=tag2[i]=0;
		if(s[l[i]-1]==0)tag1[i]=1;
		if(s[r[i]]==0)tag2[i]=1;
		S.insert(i);
	}
	while(S.size()){
		int u=*S.begin();S.erase(u);
		if(!tag1[u] || !tag2[u])break;
		upd(l[u],r[u]);
	}
	
	check();
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)solve();


	return 0;
}