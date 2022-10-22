#include<bits/stdc++.h>
using namespace std;
mt19937 rnd(random_device{}());
int rint(int l,int r){return uniform_int_distribution<int>(l,r)(rnd);}
typedef long long ll;
const int N=1e3+5;
int n,a[N];ll L,l[N],r[N];
ll qry(int i,ll x){cout<<"? "<<i<<" "<<x<<endl;cin>>x;return x;}
void solve(int l1,int r1,ll l2,ll r2){
	if(l1==r1)return l[a[l1]]=l2,r[a[l1]]=r2,void();
	int m1=(l1+r1)/2;
	ll x=L/n*m1,m2;
	static int b[N];
	for(int l=l1,r=r1;;){
		int i=rint(l,r);
		ll lb=l2,rb=r2;
		while(lb<rb){
			ll mb=(lb+rb)/2;
			if(qry(a[i],mb)<x)lb=mb+1;
			else rb=mb;
		}
		int l2=l,r2=r;
		vector<int>e;
		for(int j=l;j<=r;j++){
			ll y=qry(a[j],lb);
			if(y>x)b[l2++]=a[j];
			else if(y<x)b[r2--]=a[j];
			else e.push_back(a[j]);
		}
		for(int j=0;j<(int)e.size();j++)b[l2+j]=e[j];
		copy(b+l,b+r+1,a+l);
		if(l2<=m1&&m1<=r2){m2=lb;break;}
		if(l2<m1)l=l2+1;
		else r=l2-1;
	}
	solve(l1,m1,l2,m2);
	solve(m1+1,r1,m2,r2);
}
signed main(){
	cin>>n>>L;iota(a+1,a+1+n,1);
	solve(1,n,0,1e18);
	cout<<"!\n";
	for(int i=1;i<=n;i++)cout<<l[i]<<" "<<r[i]<<'\n';
	cout<<endl;
	cerr<<"";
}