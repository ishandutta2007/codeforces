#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
int pre[N];
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		int ans=n+1;
		for(i=1;i<=n;i++){
			if(pre[a[i]]) ans=min(ans,i-pre[a[i]]+1);
			pre[a[i]]=i;
		}
		if(ans==n+1) cout<<-1<<endl;
		else cout<<ans<<endl;
		for(i=1;i<=n;i++) pre[a[i]]=0;
	}
	return 0;
}