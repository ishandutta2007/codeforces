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
	vector<pair<int, int>>ev;//1
	vector<pair<int, int>>odd;//2
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if((i+j)%2==0){
				ev.pb({i, j});
			}
			else{
				odd.pb({i, j});
			}
		}
	}
	int pt1=0;
	int pt2=0;
	for(int i=0; i<n*n; i++){
		int x;
		cin>>x;
		if(pt1==ev.size()){
			if(x==2){
				cout<<3<<" "<<odd[pt2].f<<" "<<odd[pt2].s<<endl;
			}
			else{
				cout<<2<<" "<<odd[pt2].f<<" "<<odd[pt2].s<<endl;
			}
			pt2++;
			continue;
		}
		if(pt2==odd.size()){
			if(x==1){
				cout<<3<<" "<<ev[pt1].f<<" "<<ev[pt1].s<<endl;
			}
			else{
				cout<<1<<" "<<ev[pt1].f<<" "<<ev[pt1].s<<endl;
			}
			pt1++;
			continue;
		}
		if(x==3){
			cout<<1<<" "<<ev[pt1].f<<" "<<ev[pt1].s<<endl;
			pt1++;
			continue;
		}
		if(x==1){
			cout<<2<<" "<<odd[pt2].f<<" "<<odd[pt2].s<<endl;
			pt2++;
			continue;
		}
		if(x==2){
			cout<<1<<" "<<ev[pt1].f<<" "<<ev[pt1].s<<endl;
			pt1++;
			continue;
		}
	}
	
	
	return 0;
}