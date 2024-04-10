#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int rev[100010];
vector<pair<int,int> > v;
vector<int> r,y;

inline void dfs(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	dfs(l,mid);dfs(mid+1,r);
	for(int i=l;i<=mid;i++) v.push_back(make_pair(i,i+mid-l+1)); 
}

inline void calc(int r,int c)
{
	for(int i=1;i<=c;i++) v.push_back(make_pair(y[i-1],r+i-1));
	for(int i=1;i<=c;i++) y.push_back(r+i-1);
}

signed main()
{
	ios::sync_with_stdio(false);
	int n;cin>>n;
	if(n==1||n==2){
		cout<<0<<endl;
		return 0;
	}
	int now=1;
	for(int i=20;i>=0;i--) if(n&(1<<i)){
		dfs(now,now+(1<<i)-1);
		now+=(1<<i);
		r.push_back((1<<i));
	}
	if(r.size()==1||r.size()==2){
		cout<<v.size()<<'\n';
		for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<'\n';
		return 0;
	}
	rev[r.size()-1]=r[r.size()-1];
	for(int i=r.size()-2;i>=0;i--) rev[i]=rev[i+1]+r[i];
	int sum=1;
	for(int i=n;i>=n-r[r.size()-1]+1;i--) y.push_back(i);
	for(int i=r.size()-1;i>=2;i--){
		int val=r[i];
		while(val!=r[i-1]){
			calc(sum,val);
			sum+=val;
			val*=2;
		}
		int pos=i-1;
		while(pos>=1){
			if(val!=r[pos]) break;
			calc(n-rev[pos]+1,val);
			val*=2;pos--;
		}
		pos++;r[pos]=val;i=pos+1;
	}
	cout<<v.size()<<'\n';
	for(int i=0;i<v.size();i++) cout<<v[i].first<<" "<<v[i].second<<'\n';
	return 0;
}