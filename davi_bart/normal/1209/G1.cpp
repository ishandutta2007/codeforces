#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> p;
vector<ll> last(200009,0);
vector<ll> sizee(200009,0);
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ll N,Q;
		cin>>N>>Q;
		ll tot=0;
		for(ll i=0;i<N;i++){
			ll a;
			cin>>a;
			p.push_back(a);
			last[a]=i;
			sizee[a]++;
		}
		p.push_back(0);
		ll inizio=0;
		ll fine=0;
		ll ma=0;
		for(ll i=0;i<N;i++){
			fine=max(fine,last[p[i]]);
			ma=max(ma,sizee[p[i]]);
			if(i==fine){
        tot+=i-inizio-ma+1;
        ma=0;
        inizio=i+1;
			}
		}
		cout<<tot;
		return 0;
}