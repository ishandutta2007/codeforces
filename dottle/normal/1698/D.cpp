#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;
using vi=vector<int>;

vi ask(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	vector<int> a(r-l+1);
	for(auto&x:a)cin>>x;
	return a;	
}
void ans(int k){
	cout<<"! "<<k<<endl;
}

void solve(){
	int n;cin>>n;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)>>1;
		auto a=ask(l,mid);
		int cnt=0;
		for(auto x:a)if(x>=l&&x<=mid)cnt++;
		if(cnt&1)r=mid;
		else l=mid+1;
	}
	ans(l);
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}