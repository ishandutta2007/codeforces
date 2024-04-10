    #include <bits/stdc++.h>
    using namespace std;
    int a[2003],ans=1e9;
    map <int,int> vis;
    int main(){
    	int n;cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=0;i<=n;i++){
    		vis.clear();
    		for (int j=1;j<=i;j++){
				if (vis[a[j]]) break;
				vis[a[j]]=1;
   			}
    		for (int k=n;k>=i+1;k--){
    			if (vis[a[k]]) break;
    			vis[a[k]]=1;
    		}
    		ans=min(ans,n-(int)(vis.size()));
    	}
    	cout<<ans<<"\n";
    }