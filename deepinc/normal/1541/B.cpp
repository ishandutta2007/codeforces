#include<bits/stdc++.h>
using namespace std;
int a[200005],pos[400005],ans;
int main(){
	int t; cin>>t; while(t--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),pos[a[i]]=i;
		for(int i=1;i<=n;++i)for(int j=n*2/a[i];j;j--)
			if(i<pos[j]&&i+pos[j]==a[i]*j)ans++;
		printf("%d\n",ans); ans=0;
		for(int i=1;i<=n;++i)pos[a[i]]=0;
	}
}