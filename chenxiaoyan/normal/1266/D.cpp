/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define X first
#define Y second
#define mp make_pair
const int N=100000;
int n,m;
int hav[N+1];
signed main(){
	cin>>n>>m;
	while(m--){
		int x,y,z;
		cin>>x>>y>>z;
		hav[x]-=z;hav[y]+=z;
	}
	set<pair<int,int> > st;
	for(int i=1;i<=n;i++)if(hav[i])st.insert(mp(hav[i],i));
	vector<pair<int,pair<int,int> > > ans;
	while(st.size()){
		int x=st.begin()->Y,y=(--st.end())->Y;
		st.erase(st.begin());st.erase(--st.end());
		int debt=min(-hav[x],hav[y]);
		ans.pb(mp(x,mp(y,debt)));
		hav[x]+=debt;hav[y]-=debt;
		if(hav[x])st.insert(mp(hav[x],x));
		if(hav[y])st.insert(mp(hav[y],y));
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)printf("%lld %lld %lld\n",ans[i].X,ans[i].Y.X,ans[i].Y.Y);
	return 0;
}