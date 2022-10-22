#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=400005;
const int inf=0x3f3f3f3f;
int n,m,k;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(i=n;i;i--) cout<<a[i]<<" ";
		cout<<endl;
	}
	return 0;
}