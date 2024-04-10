#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n;
	cin>>n;
	lli ans=1;
	lli plus=0;
	for(lli i=2;i<=n;i++){
		plus+=4;
		ans+=plus;
	}
	printf("%lli\n",ans);
	return 0;
}