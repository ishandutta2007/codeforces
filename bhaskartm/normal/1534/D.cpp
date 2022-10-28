#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
const int N=2005;
int n;

int d[N];
vector<int>ev;
vector<int>od;



 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	cout<<"? "<<1<<endl;
	for(int i=1; i<=n; i++){
		cin>>d[i];
		if(d[i]%2==0){
			ev.pb(i);
		}
		else{
			od.pb(i);
		}
	}
	int se=ev.size();
	int so=od.size();
	vector<pair<int, int>>ed;
	
	if(so<se){
		for(auto u:od){
			cout<<"? "<<u<<endl;
			for(int i=1; i<=n; i++){
				int x;
				cin>>x;
				if(x==1){
					ed.pb({u, i});
				}
			}
		}
	}
	else{
		for(int i=1; i<=n; i++){
			if(d[i]==1){
				ed.pb({1, i});
			}
		}
		for(auto u:ev){
			if(u!=1){
				cout<<"? "<<u<<endl;
				for(int i=1; i<=n; i++){
					int x;
					cin>>x;
					if(x==1){
						ed.pb({u, i});
					}
				}
			}
		}
	}
	cout<<"!"<<endl;
	for(auto u:ed){
		cout<<u.f<<" "<<u.s<<endl;
	}
	
	return 0;
}