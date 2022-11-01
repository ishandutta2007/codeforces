#include<bits/stdc++.h>
#define ll long long
#define N 200005
#define mp make_pair
#define fi first
#define se second
using namespace std;
template<typename T>void read(T &x){
	char c=getchar();int f=1;x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();
	x*=f;
}
int n,X[N],Y[N],x[N],y[N];
ll ans;
void solve(){
	read(n);
	for(int i=1;i<=n;i++)X[i]=Y[i]=0;
	for(int i=1;i<=n;i++)read(x[i]),read(y[i]),X[x[i]]++,Y[y[i]]++;
	ans=1ll*n*(n-1)*(n-2)/6ll;
	for(int i=1;i<=n;i++)ans-=1ll*(X[x[i]]-1ll)*(Y[y[i]]-1ll);
	cout<<ans<<'\n';
}
int main(){
	int T;read(T);
	while(T--)solve();
	return 0;
}