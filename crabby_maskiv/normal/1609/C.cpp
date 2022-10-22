#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e6+5;
int n,m;
bool np[N];
int pri[N],len;
void euler(){
	int i,j;
	for(i=2;i<N;i++){
		if(!np[i]){
			pri[++len]=i;
		}
		for(j=1;j<=len;j++){
			if(i*pri[j]>=N) break;
			np[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int a[N];
int nxt[N];
int main(){
	int i,j;
	euler();
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=n+1;i<=n+m;i++){
			nxt[i]=i;
			a[i]=4;
		}
		ll ans=0;
		for(i=n;i;i--){
			if(a[i]==1) nxt[i]=nxt[i+m];
			else nxt[i]=i;
			if(np[a[nxt[i]]]) continue;
			ans+=(nxt[nxt[i]+m]-nxt[i])/m-(nxt[i]==i);
		}
		cout<<ans<<endl;
	}
	return 0;
}