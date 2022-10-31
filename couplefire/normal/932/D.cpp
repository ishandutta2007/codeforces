#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

int par[20][400000];
ll par_sum[20][400000];
int w[400000];

void solve(){
	int Q;
	cin>>Q;
	w[0]=INT_MAX;
	int last=0;
	int cur=1;
	for(int i=0;i<20;i++)par_sum[i][1]=1e16;
	while(Q--){
		int ch;
		cin>>ch;
		if(ch==1){
			ll p,q;
			cin>>p>>q;
			p^=last;
			q^=last;
			cur++;
			w[cur]=q;
			if(w[p]>=w[cur]){
				par[0][cur]=p;
			}
			else{
				int from=p;
				for(int i=19;i>=0;i--){
					if(w[par[i][from]]<w[cur])
						from=par[i][from];
				}
				par[0][cur]=par[0][from];
			}
			par_sum[0][cur]=(par[0][cur]==0?1e16:w[par[0][cur]]);
			for(int i=1;i<20;i++){
				par[i][cur]=par[i-1][par[i-1][cur]];
				par_sum[i][cur]=(par[i][cur]==0?1e16:par_sum[i-1][cur]+par_sum[i-1][par[i-1][cur]]);
			}
		}
		else{
			ll p,q;
			cin>>p>>q;
			p^=last;
			q^=last;
			if(w[p]>q){
				cout<<0<<endl;
				last=0;
			}
			else{
				q-=w[p];
				int ans=1;
				for(int i=19;i>=0;i--){
					if(par_sum[i][p]<=q){
						ans+=(1<<i);
						q-=par_sum[i][p];
						p=par[i][p];
					}
				}
				cout<<ans<<endl;
				last=ans;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}