/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define ppb pop_back
const int inf=0x3f3f3f3f;
const int N=2000,M=N,V=1000000;
int n,m;
pair<int,int> a[N+1];
pair<int,int> b[M+1];
vector<pair<int,int> > v;
vector<pair<int,int> > chg[V+1];
int now[N+1];
int cnt[V+1];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i].X>>a[i].Y;
	for(int i=1;i<=m;i++)cin>>b[i].X>>b[i].Y;
	sort(b+1,b+m+1);
	v.pb(mp(-1,V+1));
	for(int i=1;i<=m;i++){
		while(v.back().Y<=b[i].Y)v.ppb();
		v.pb(b[i]);
	}
	v.pb(mp(V+1,-1));
//	for(int i=0;i<v.size();i++)cout<<v[i].X<<" "<<v[i].Y<<"!\n";
	for(int i=1;i<=n;i++)for(int j=0;j+1<v.size();j++)
		chg[max(0,v[j].X-a[i].X+1)].pb(mp(i,max(0,v[j+1].Y-a[i].Y+1)));
	int ans=inf;
	multiset<int> st;
	for(int i=1;i<=n;i++)st.insert(0);
	for(int i=0;i<=V;i++){
		for(int j=0;j<chg[i].size();j++){
			int old=now[chg[i][j].X],nw=chg[i][j].Y;
			now[chg[i][j].X]=chg[i][j].Y;
			st.erase(st.find(old)),st.insert(nw);
		}
		ans=min(ans,*--st.end()+i);
	}
	cout<<ans;
	return 0;
}