#include<bits/stdc++.h>
using namespace std;

const int maxn=100005;

int n;
int h[maxn];
int pfx[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>h[i];
	for(int i=n;i>=1;i--) pfx[i]=max(h[i],pfx[i+1]);
	for(int i=1;i<=n;i++){
		cout<<max(pfx[i+1]-h[i]+1,0)<<' ';
	}
	return 0;
}