#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const int inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int a[N];
int f[N],l[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=m;i++) cin>>a[i];
	memset(f,0x3f,sizeof(f));
	for(i=1;i<=m;i++){
		f[a[i]]=min(f[a[i]],i);
		l[a[i]]=max(l[a[i]],i);
	}
	int ans=0;
	for(i=1;i<=n;i++){
		for(j=-1;j<=1;j++){
			int k=i+j;
			if(!k||k>n) continue;
			if(f[i]==inf){
				ans++;
				continue;
			}
			if(l[k]<f[i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}