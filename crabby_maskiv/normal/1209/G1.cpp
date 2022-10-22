#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int s[N];
int cnt[N];
int mxp;
int mn[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	memset(mn,0x3f,sizeof(mn));
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++) mn[a[i]]=min(mn[a[i]],i);
	s[n+1]=inf;
	for(i=n;i;i--)
		s[i]=min(s[i+1],mn[a[i]]);
	int pos=1;
	cnt[a[1]]++;mxp=a[1];
	int ans=0;
	for(i=2;i<=n;i++){
		if(s[i]==i){
			ans+=(i-pos)-cnt[mxp];
			for(j=pos;j<i;j++) cnt[a[j]]--;
			pos=i;
			mxp=a[i];
		}
		cnt[a[i]]++;
		if(cnt[a[i]]>cnt[mxp]) mxp=a[i];
	}
	ans+=(i-pos)-cnt[mxp];
	cout<<ans;
	return 0;
}