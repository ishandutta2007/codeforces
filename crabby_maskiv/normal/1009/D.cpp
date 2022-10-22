#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
ll pri[N],phi[N];
bool np[N];
int len;
void getphi(){
	ll i,j;
	phi[1]=1;
	for(i=2;i<N;i++){
		if(!np[i]){
			pri[++len]=i;
			phi[i]=i-1;
		}
		for(j=1;j<=len;j++){
			if(i*pri[j]>=N) break;
			if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else phi[i*pri[j]]=phi[i]*pri[j];
			np[i*pri[j]]=1;
		}
	}
}
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	getphi();
	ll sum=0;
	for(i=2;i<=n;i++) sum+=phi[i];
	if(sum<m||m<n-1){
		cout<<"Impossible";
		return 0;
	}
	cout<<"Possible"<<endl;
	for(i=2;i<=n;i++){
		cout<<i-1<<" "<<i<<endl;
		m--;
	}
	for(i=n;i;i--){
		for(j=1;j<i-1;j++){
			if(!m) return 0;
			if(gcd(i,j)==1){
				cout<<i<<" "<<j<<endl;
				m--;
			}
		}
	}
    return 0;
}