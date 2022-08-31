#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>

map<pii,int> dis;
map<int, vc<pii> > z,segs;
int check(pii z){
	if(z.fr<1||z.sc<1)return 0;
	pii yo={z.sc+1,0};
	auto it=lower_bound(all(segs[z.fr]),yo);
	if(it==segs[z.fr].begin())return 0;
	it--;
	if((*it).sc<z.sc)return 0;
	return 1;
}
void solve(){
	int x0,y0,x1,y1;
	cin>>x0>>y0>>x1>>y1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int r,a,b;
		cin>>r>>a>>b;
		z[r].pb({a,b});
	}
	for(auto u:z){
		sort(all(u.sc));
		int clo=u.sc[0].sc;segs[u.fr].pb({u.sc[0].fr,-1});
		for(int i=1;i<u.sc.size();i++){
			if(u.sc[i].fr>clo){
				segs[u.fr].back().sc=clo;
				segs[u.fr].pb({u.sc[i].fr,-1});
				clo=u.sc[i].sc;
			}
			else{
				clo=max(clo,u.sc[i].sc);
			}
		}
		if(segs[u.fr].back().sc==-1)segs[u.fr].back().sc=clo;
	}
	deque<pii> dq;
	dq.pb({x0,y0});int found=0;
	dis[{x0,y0}]=0;
	while(!dq.empty()){
		pii z=dq.front();
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(i==0&&j==0)continue;
				if(!check({z.fr+i,z.sc+j}))continue;
				
				if(dis.find({z.fr+i,z.sc+j})==dis.end()){
					dq.pb({z.fr+i,z.sc+j});
					dis[{z.fr+i,z.sc+j}]=dis[z]+1;
					if((z.fr+i==x1)&&(z.sc+j==y1)){cout<<dis[{x1,y1}];return;}
				}
			}
		}
		dq.pop_front();
	}
	cout<<-1;
}
signed main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t=1;
    //cin>>t;
	while(t--) solve();
	return 0;
}