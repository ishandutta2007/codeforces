#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,l,r;
int a[N];
int c[N];
bool vis[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>l>>r;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) c[i]=vis[i]=0;
		for(i=1;i<=l;i++) c[a[i]]++;
		for(i=l+1;i<=n;i++){
			if(c[a[i]]){
				c[a[i]]--;
				vis[i]=1;
			}
		}
		for(i=1;i<=n;i++) c[i]=0;
		for(i=l+1;i<=n;i++) c[a[i]]++;
		for(i=1;i<=l;i++){
			if(c[a[i]]){
				c[a[i]]--;
				vis[i]=1;
			}
		}
		int cl=0,cr=0,ans;
		for(i=1;i<=l;i++) cl+=(vis[i]==0);
		for(i=l+1;i<=n;i++) cr+=(vis[i]==0);
		for(i=1;i<=n;i++) c[i]=0;
		if(cl>cr){
			int cnt=0;
			for(i=1;i<=l;i++){
				if(vis[i]) continue;
				if(c[a[i]]){
					cnt++;
					vis[c[a[i]]]=vis[i]=1;
					c[a[i]]=0;
				}
				else c[a[i]]=i;
			}
			if(cnt>=(cl-cr)/2) ans=cl+cr>>1;
			else ans=cr+(cl-cr-cnt*2)+cnt;
		}
		else{
			int cnt=0;
			for(i=l+1;i<=n;i++){
				if(vis[i]) continue;
				if(c[a[i]]){
					cnt++;
					vis[c[a[i]]]=vis[i]=1;
					c[a[i]]=0;
				}
				else c[a[i]]=i;
			}
			if(cnt>=(cr-cl)/2) ans=cl+cr>>1;
			else ans=cl+(cr-cl-cnt*2)+cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}