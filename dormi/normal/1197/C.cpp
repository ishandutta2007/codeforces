#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	lli n,k;
	cin>>n>>k;
	lli arr[n+1]={};
	lli diffs[n-1];
	for(lli i=1;i<=n;i++){
		cin>>arr[i];
		if(i>=2){
			diffs[i-2]=arr[i]-arr[i-1];
		}
	}
	sort(diffs,diffs+n-1);
	lli amneeded=n-k;
	lli ans=0;
	for(int i=0;i<amneeded;i++){
		ans+=diffs[i];
	}
	printf("%lli\n",ans);
    return 0;
}