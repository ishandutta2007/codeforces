#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
#define s second
#define f first
int sv[100005];
int taken[100005];
main() {
	int n;
	cin>>n;
	for(int x=2; x<=n; x++){
		if(sv[x]){
			continue;
		}
		for(int u=2*x; u<=n; u=u+x){
			sv[u]=x;
		}
	}
	vector<int>v;
	for(int i=3; i<=(n/2); i++){
		if(sv[i]==0){
			v.pb(i);
		}
	}
	vector<int>ans;
	vector<int>temp2;
	for(auto u:v){
		vector<int>temp;
		for(int j=u; j<=n; j=j+u){
			if(taken[j]==0){
				temp.pb(j);
			}
		}
		if(temp.size()%2==0){
			for(auto u:temp){
				taken[u]=1;
				ans.pb(u);
			}
		}
		else{
			for(int i=0; i<temp.size(); i++){
				if(i==1){
					temp2.pb(temp[i]);
					taken[temp[i]]=1;
				}
				else{
					ans.pb(temp[i]);
					taken[temp[i]]=1;
				}
			}
		}
	}
	for(int i=2; i<=n; i=i+2){
		if(taken[i]==0){
			temp2.pb(i);
		}
	}
	if(temp2.size()%2==1){
		temp2.pop_back();
	}
	cout<<(ans.size()+temp2.size())/2<<endl;
	for(int i=0; i<ans.size(); i=i+2){
		cout<<ans[i]<<" "<<ans[i+1]<<endl;
	}
	for(int i=0; i<temp2.size(); i=i+2){
		cout<<temp2[i]<<" "<<temp2[i+1]<<endl;
	}
	return 0;
}