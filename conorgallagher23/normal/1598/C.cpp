#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define mp make_pair
#define fi first
#define se second
using namespace std;
template<typename T>void read(T &x){
	char c=getchar();ll f=1;x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	x*=f;
}
ll n,a[N],s;
map<ll,ll>T;
void solve(){
	read(n);s=0ll;
	for(int i=1;i<=n;i++)read(a[i]),s+=1ll*a[i];
	if(s*2ll%n!=0){
		cout<<"0\n";
		return;
	}
	T.clear();
	ll tmp=s*2ll/n,ans=0ll;
	for(int i=1;i<=n;i++){
		ans+=1ll*T[tmp-a[i]];
		T[a[i]]++;
	}
	cout<<ans<<'\n';
}
int main(){
	int T;read(T);
	while(T--)solve();
	return 0;
}