#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1);
		for(i=1;i<=n;i++){
			if(a[i]<a[n-i+1]) swap(a[i],a[n-i+1]);
			if(a[i]-a[n-i+1]==2) continue;
			if(a[i]-a[n-i+1]==0) continue;
			cout<<"NO"<<endl;
			break;
		}
		if(i>n) cout<<"YES"<<endl;
	}
	return 0;
}