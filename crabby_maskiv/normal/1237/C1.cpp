#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll x[N],y[N],z[N];
ll f(ll a){
	if(a<0) return -a;
	return a;
}
ll mht(int i,int j){
	return f(x[i]-x[j])+f(y[i]-y[j])+f(z[i]-z[j]);
}
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)
    	cin>>x[i]>>y[i]>>z[i];
    x[0]=y[0]=z[0]=inf;
	for(i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		int pos=0;
		for(j=1;j<=n;j++){
			if(vis[j]) continue;
			if(mht(i,j)<mht(i,pos)) pos=j;
		}
		vis[pos]=1;
		cout<<i<<" "<<pos<<endl;
	}
    return 0;
}