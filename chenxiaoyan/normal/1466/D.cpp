/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=100000;
int n;
int a[N+1];
int deg[N+1];
vector<int> nei[N+1];
void mian(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++)deg[i]=0,nei[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		deg[x]++,deg[y]++;
		nei[x].pb(y),nei[y].pb(x);
	}
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[i];
	priority_queue<pair<int,int> > q;
	for(int i=1;i<=n;i++)q.push(mp(a[i],i));
	for(int i=1;i+1<n;i++){
		cout<<ans<<" ";
		int x=q.top().Y;
		while(deg[x]==1)q.pop(),x=q.top().Y;
		ans+=a[x];
		deg[x]--;
	}
	cout<<ans<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}