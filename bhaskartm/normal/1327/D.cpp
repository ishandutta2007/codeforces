#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+1];
		int c[n+1];
		a[0]=0;
		c[0]=0;
		for(int i=1; i<=n; i++){
			cin>>a[i];
		}
		for(int i=1; i<=n; i++){
			cin>>c[i];
		}
		int vis[n+1];
		for(int i=0; i<=n; i++){
			vis[i]=0;
		}
		
		int mini=1e9;
		for(int i=1; i<=n; i++){
			
			if(vis[i]){
				continue;
			}
			vector<int>cycle;
			int node=a[i];
			vis[i]=1;
			vis[node]=1;
			cycle.push_back(i);
			while(node!=i){
				cycle.push_back(node);
				node=a[node];
				vis[node]=1;
			}
			
			
			int sz=cycle.size();
			if(sz==1){
				mini=1;
				break;
			}
			vector<int>f;
			for(int x=1; x*x<=sz; x++){
				if(sz%x==0){
					f.push_back(x);
					f.push_back(sz/x);
				}
			}
			
			for(auto u:f){
				
				for(int j=0; j<=u-1; j++){
					bool b=1;
					
					int color=c[cycle[j]];
					int node2=cycle[(j+u)%sz];
					int index=(j+u)%sz;
					while(node2!=cycle[j]){
						if(color!=c[node2]){
							b=0;
						}
						index=(index+u)%sz;
						node2=cycle[index];
						
					}
					if(b==1){
						mini=min(mini, u);
					}
				}
				
			}
		}
		cout<<mini<<endl;
	}
	
	return 0;
}