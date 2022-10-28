#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back




main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int ans[n+1];
	bool don[n+1];
	vector<int>v;
	for(int i=1; i<=n; i++){
		ans[i]=-1;
		v.pb(i);
		don[i]=0;
	}
	while(1){
		if(v.size()==1){
			int rem=-1;
			for(int i=1; i<=n; i++){
				if(don[i]==0){
					rem=i;
					break;
				}
			}
			ans[v[0]]=rem;
			cout<<"! ";
			for(int i=1; i<=n; i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
			return 0;
		}
		vector<int>temp;
		for(int i=0; i+1<v.size(); i=i+2){
			int x=v[i];
			int y=v[i+1];
			int x1;
			int y1;
			cout<<"?"<<" "<<x<<" "<<y;
			cout<<endl;
			cin>>x1;
			cout<<"?"<<" "<<y<<" "<<x;
			cout<<endl;
			cin>>y1;
			if(x1>y1){
				ans[x]=x1;
				don[x1]=1;
				temp.pb(y);
			}
			else{
				ans[y]=y1;
				don[y1]=1;
				temp.pb(x);
			}
		}
		if(v.size()%2==1){
			temp.pb(v.back());
		}
		v.clear();
		for(auto u:temp){
			v.pb(u);
		}
	}
	
	return 0;
}