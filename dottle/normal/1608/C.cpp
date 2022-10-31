#include<bits/stdc++.h>
//#define int long long
//const int N=
using namespace std;

void solve(){
	int n;cin>>n;
	vector<pair<int,int>> a(n),b(n);
	vector<int> rka(n),rkb(n),fl(n);
	for(int i=0;i<n;i++)cin>>a[i].first,a[i].second=i;
	for(int i=0;i<n;i++)cin>>b[i].first,b[i].second=i;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++)
		rka[a[i].second]=i,
		rkb[b[i].second]=i;
	int l=n-1,r=n-1,L=n-1,R=n-1;
	while(l>=L||r>=R){
		if(l>=L){
			fl[a[l].second]=1;
			R=min(R,rkb[a[l].second]);
			l--;
		}else{
			fl[b[r].second]=1;
			L=min(L,rka[b[r].second]);
			r--;
		}
	}
	for(auto x:fl)cout<<x;
	cout<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}