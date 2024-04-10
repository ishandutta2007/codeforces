#include <bits/stdc++.h>
using namespace std;
int t,n,a[100004],ans[100004],vis[100004];
int main(){
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i],vis[i+1]=0;
		int now=-1,cnt=1,ok=1;
		for (int i=0;i<n && ok;i++){
			if (a[i]!=now){
				if (vis[a[i]]) ok=0;
				ans[i]=a[i],now=a[i],vis[a[i]]=1;
				continue;
			}
			while (vis[cnt]) cnt++;
			if (cnt>a[i]) ok=0;
			ans[i]=cnt,vis[cnt]=1;
		}
		if (!ok) puts("-1");
		else{
			for (int i=0;i<n;i++)
				cout<<ans[i]<<" ";puts(""); 
		}
	}
}