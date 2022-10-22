#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int c[N],a[N];
int mx,cntmx,cntmx1,cnt1,cnt;
int ans;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		if(c[a[i]]==0){
			cnt++;
			cnt1++;
			if(mx==0){
				mx=1;
				cntmx=1;
			}
			else if(mx==1)
				cntmx++;
			else if(mx==2)
				cntmx1++;
		}
		else if(c[a[i]]==1){
			cnt1--;
			if(mx==1){
				mx=2;
				cntmx1=cntmx-1;
				cntmx=1;
			}
			else if(mx==2)
				cntmx++;
			else if(mx==3)
				cntmx1++;
		}
		else if(c[a[i]]==mx-2)
			cntmx1++;
		else if(c[a[i]]==mx-1){
			cntmx1--;
			cntmx++;
		}
		else if(c[a[i]]==mx){
			cntmx1=cntmx-1;
			cntmx=1;
			mx++;
		}
		c[a[i]]++;
		if(mx==1) ans=i;
		else if(cnt==cntmx+1&&cnt1==1) ans=i;
		else if(cnt==cntmx1+1&&cntmx==1) ans=i;
	}
	cout<<ans;
	return 0;
}