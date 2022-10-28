#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'



main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		map<int , vector<int>>ma;
		for(int i=0; i<m; i++){
			int r, c;
			cin>>r>>c;
			ma[c].pb(r);
		}
		int curr=0;
		bool che=1;
		int col=1;
		for(auto it=ma.begin(); it!=ma.end(); it++){
			vector<int>v=(it->second);
			int c=(it->first);
			
			if(curr!=0 && v.size()==2){
				che=0;
				break;
			}
			if(v.size()==2){
				col=c+1;
				continue;
			}
			int r=v[0];
			if(curr==0){
				if(r==2){
					curr=1;
					col=c+1;
					
					continue;
				}
				if(r==1){
					curr=-1;
					col=c+1;
					continue;
				}
			}
			if(curr==1){
				if(r==1){
					if((c-col)%2==0){
						che=0;
						break;
					}
					else{
						curr=0;
						col=c+1;
						continue;
					}
				}
				if(r==2){
					if((c-col)%2==1){
						che=0;
						break;
					}
					else{
						curr=0;
						col=c+1;
						continue;
					}
				}
			}
			else{
				if(r==1){
					if((c-col)%2==1){
						che=0;
						break;
					}
					else{
						curr=0;
						col=c+1;
						continue;
					}
				}
				if(r==2){
					if((c-col)%2==0){
						che=0;
						break;
					}
					else{
						curr=0;
						col=c+1;
						continue;
					}
				}
			}
		}
		if(che && m%2==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}