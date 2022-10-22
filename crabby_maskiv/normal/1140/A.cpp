#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	int pos=1;
	int ans=0;
	for(i=1;i<=n;i++){
		pos=max(pos,a[i]);
		if(pos<=i){
			pos=i;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}