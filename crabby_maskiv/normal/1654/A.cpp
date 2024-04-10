#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e3+5;
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
		sort(a+1,a+n+1);
		cout<<a[n]+a[n-1]<<endl;
	}
	return 0;
}