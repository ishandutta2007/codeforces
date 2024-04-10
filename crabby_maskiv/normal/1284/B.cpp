#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=1000005;
const int inf=0x3f3f3f3f;
int n,m;
int mx[N],mn[N];
int s[N];
bool flag[N];
int main(){
	int i,j;
	cin>>n;
	ll ans=0;
	for(i=1;i<=n;i++){
		mn[i]=inf;
		cin>>m;
		int tmp=inf;
		for(j=1;j<=m;j++){
			int x;cin>>x;
			if(x>tmp&&!flag[i]){
				flag[i]=1;
				ans+=2*n-1;
			}
			tmp=min(tmp,x);
			mx[i]=max(mx[i],x);
			mn[i]=min(mn[i],x);
		}
	}
	int tmp=0;
	for(i=1;i<=n;i++) if(flag[i]) tmp++;
	ans-=ll(tmp-1)*tmp;
	for(i=1;i<=n;i++)
		if(!flag[i]) s[mn[i]]++;
	for(i=1;i<N;i++) s[i]+=s[i-1];
	for(i=1;i<=n;i++)
		if(!flag[i]) ans+=s[mx[i]-1];
	cout<<ans;
	return 0;
}