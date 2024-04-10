/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5000;
int n,m;
int a[N+1];
signed main(){
	cin>>n>>m;
	int res=0;
	for(int i=1;i<=n;i++)res+=(i-1)/2;
	if(res<m)return puts("-1"),0;
	int now=1000010000;
	for(int i=1;i<=n;i++)a[i]=i;
	for(int i=n;;i--){
		if(res-m>(i-1)/2)res-=(i-1)/2,a[i]=now-=10000;
		else{a[i]+=res-m<<1;break;}
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}