#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,l,r;
	cin>>n>>l>>r;
	lli mi=n-(l-1);
	lli cnt=2;
	for(int i=1;i<l;i++){
		mi+=cnt;
		cnt*=2;
	}
	printf("%lli ",mi);
	lli ma=0;
	cnt=1;
	for(int i=0;i<r;i++){
		ma+=cnt;
		cnt*=2;
	}
	cnt/=2;
	ma+=(n-r)*cnt;
	printf("%lli\n",ma);
	return 0;
}