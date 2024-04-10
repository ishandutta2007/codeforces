/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int inf=0x3f3f3f3f;
const int N=100000;
int n;
vector<int> a[N+1];
int yes[N+1];
int mn[N+1],mx[N+1];
int main(){
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int m;
		cin>>m;
		mn[i]=inf;mx[i]=-inf;
		while(m--){
			int x;
			cin>>x;
			mn[i]=min(mn[i],x);mx[i]=max(mx[i],x);
			a[i].pb(x);
		}
		bool flg=true;
		for(int j=0;j+1<a[i].size();j++)flg&=a[i][j]>=a[i][j+1];
		yes[i]=!flg;
		cnt+=!flg;
	}
	long long res=0;
	vector<int> v;
	for(int i=1;i<=n;i++)if(!yes[i])v.pb(mx[i]);
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)
		if(yes[i])res+=n;
		else res+=cnt+v.end()-upper_bound(v.begin(),v.end(),mn[i]);
	cout<<res<<"\n";
	return 0;
}