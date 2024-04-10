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
		int n;
		cin>>n;
		int ind=-1;
		vector<pair<int, int>>v;
		for(int i=2; i<n; i++){
			v.clear();
			int x1=i;
			int x2=n;
			int steps=0;
			bool che=1;
			while(1){
				if((x1==1 && x2==2) || (x2==1 && x1==2)){
					break;
				}
				if(x1==x2 && x1==2){
					v.pb({i, n});
					steps++;
					break;
				}
				if(x1==x2){
					che=0;
					break;
				}
				if(x1>x2){
					steps++;
					if(x1%x2==0){
						x1=(x1/x2);
					}
					else{
						x1=(x1/x2)+1;
					}
					v.pb({i, n});
					continue;
				}
				else{
					steps++;
					if(x2%x1==0){
						x2=(x2/x1);
					}
					else{
						x2=(x2/x1)+1;
					}
					v.pb({n,i});
				}
			}
			if(che==0){
				continue;
			}
			if(steps<=8){
				ind=i;
				break;
			}
		}
		cout<<v.size()+n-3<<endl;
		for(int i=2; i<=n-1; i++){
			if(ind==i){
				continue;
			}
			cout<<i<<" "<<n<<endl;
		}
		for(auto u:v){
			cout<<u.f<<" "<<u.s<<endl;
		}
	}
	return 0;
}