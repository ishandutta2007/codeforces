#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first
#define s second

ll ans,N,T,K;
ll a,b,c,d;

int main(){
	cin>>T;
	while(T--){
		cin>>N>>K;
		cin>>a>>b>>c>>d;
		ans=0;
		if(a>c){
			swap(a,c);swap(b,d);
		}
		ll ov=0;
		if(b>c){
			ov=min(b,d)-c;
			K -= N*(min(b,d)-c);
		}
		if(K<0){
			cout<<"0\n";
			continue;
		}
		for(int i=0;i<N;++i)if(K>0){
			ll ds=max(0LL,c-b);
			ll maxkt = max(b,d)-a-ov;
			maxkt=min(maxkt,K);
			if(maxkt<ds && i>0)break;
			ans+=ds;
			K-=maxkt;
			ans+=maxkt;
		}
		assert(K>=0);
		ans+=K*2;
		cout<<ans<<'\n';
	}
}