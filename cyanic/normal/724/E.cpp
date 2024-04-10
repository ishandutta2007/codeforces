#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define x first
#define y second
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
 
const int N=10005;
ll f[N],g[N],p[N],s[N],c,ans=1e18;
int n;
 
int main(){
	cin>>n>>c;
	rep(i,1,n)cin>>p[i];
	rep(i,1,n)cin>>s[i];
	memset(f,0x3f,sizeof f);
	f[0]=0;
	rep(i,1,n){
		memset(g,0x3f,sizeof g);
		rep(j,0,i-1){
			g[j+1]=min(g[j+1],f[j]+s[i]);
			g[j]=min(g[j],f[j]+p[i]+j*c);
		}
		rep(j,0,i)f[j]=g[j];
	}
	rep(i,0,n)ans=min(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}