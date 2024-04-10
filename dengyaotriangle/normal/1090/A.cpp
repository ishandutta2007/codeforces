#include<bits/stdc++.h>
using namespace std;

const int maxn=200005;

struct CP{
	int n;
	int mx;
};
int n;
vector<int> m[maxn];
CP cp [maxn];

bool cmp(CP a,CP b){
	return a.mx<b.mx;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cp[i].n ;
		for(int j=0;j<cp[i].n;j++){
			int _;
			cin>>_;
			cp[i].mx=max(cp[i].mx,_);
		}
	}
	long long ans=0;
	sort(cp+1,cp+1+n,cmp);
	long long pfx=cp[1].n;
	for(int i=2;i<=n;i++){
		ans+=(cp[i].mx-cp[i-1].mx )*pfx;
		pfx+=cp[i].n;
	}
	cout<<ans;
	return 0;
}