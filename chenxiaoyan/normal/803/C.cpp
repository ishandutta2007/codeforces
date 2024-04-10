/*








*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
int n,m;
signed main(){
	cin>>n>>m;
	int sum=m>=1000000?inf:m*(m+1)/2;
	vector<int> div;
	for(int i=1;i*i<=n;i++)if(n%i==0)div.pb(i),div.pb(n/i);
	sort(div.begin(),div.end());
	for(int i=div.size()-1;~i;i--){
		int nwn=n/div[i];
		if(nwn>=sum){
			for(int j=1;j<m;j++)cout<<j*div[i]<<" ";
			cout<<(nwn-(m-1)*m/2)*div[i];
			return 0;
		}
	}
	puts("-1");
	return 0;
}
/*1
24 2
*/