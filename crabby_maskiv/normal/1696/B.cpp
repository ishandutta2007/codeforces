#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		int c0=0;
		for(i=1;i<=n;i++) c0+=(a[i]==0);
		if(c0==n){
			cout<<0<<endl;
			continue;
		}
		int c=0;
		for(i=1;i<=n;i++)
			if(a[i]!=0&&a[i-1]==0) c++;
		if(c>1) cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}