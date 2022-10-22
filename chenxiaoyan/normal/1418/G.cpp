/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
void read(int &x){
	x=0;char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
}
const int N=500000;
int n;
int a[N+1];
int cnt[N+1];
int las1[N+1],las2[N+1],las3[N+1];
const int hbase1=131,hmod1=998244353,hbase2=13331,hmod2=1000000007,hshmod=19260817;
int pw1[N+1],pw2[N+1];
struct hashlist{
	vector<pair<pair<int,int>,int> > v[hshmod];
	#define g v[x.X%hshmod]
	int &operator[](pair<int,int> x){
		for(int i=0;i<g.size();i++)if(g[i].X==x)return g[i].Y;
		g.pb(mp(x,0));
		return g.back().Y;
	}
}st;
int hsh1[N+1],hsh2[N+1];
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]);
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=n;i++)pw1[i]=1ll*pw1[i-1]*hbase1%hmod1,pw2[i]=1ll*pw2[i-1]*hbase2%hmod2;
	int now=0;
	st[mp(0,0)]++;
	long long ans=0;
	memset(las1,-1,sizeof(las1));memset(las2,-1,sizeof(las2));memset(las3,-1,sizeof(las3));
	for(int i=1;i<=n;i++){
		hsh1[i]=hsh1[i-1],hsh2[i]=hsh2[i-1];
		(hsh1[i]-=1ll*cnt[a[i]]*pw1[a[i]]%hmod1)%=hmod1,(hsh2[i]-=1ll*cnt[a[i]]*pw2[a[i]]%hmod2)%=hmod2;
		(hsh1[i]+=1ll*(cnt[a[i]]=(cnt[a[i]]+1)%3)*pw1[a[i]]%hmod1)%=hmod1,(hsh2[i]+=1ll*cnt[a[i]]*pw2[a[i]]%hmod2)%=hmod2;
		(hsh1[i]+=hmod1)%=hmod1,(hsh2[i]+=hmod2)%=hmod2;
		int old_now=now;
		now=max(now,las3[a[i]]);
		for(int j=old_now;j<now;j++)st[mp(hsh1[j],hsh2[j])]--;
		las3[a[i]]=las2[a[i]],las2[a[i]]=las1[a[i]],las1[a[i]]=i;
		ans+=st[mp(hsh1[i],hsh2[i])];
		st[mp(hsh1[i],hsh2[i])]++;
	}
	cout<<ans;
	return 0;
}