#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int pos[100005];
bool don[100005];
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int sum=0;
	for(int i=n-1; i>=0; i--){
		if(arr[i]==1){
			sum++;
		}
		if(arr[i]==2 ){
			sum--;
		}
		if(sum<0){
			cout<<-1;
			return 0;
		}
	}
	set<pair<int, int>>se3;
	vector<pair<int, int>>vec;
	set<pair<int, int>>se2;
	int pt=n;
	for(int i=n-1; i>=0; i--){
		if(arr[i]==0){
			continue;
		}
		if(arr[i]==1){
			vec.pb({pt, i+1});
			
			se2.insert({pt, i+1});
			se3.insert({pt, i+1});
			pt--;
			continue;
		}
		if(arr[i]==2){
			if(se2.size()==0){
				cout<<-1;
				return 0;
			}
			
			auto it=se2.begin();
			se2.erase((*it));
			if(se3.find((*it))!=se3.end()){
				se3.erase((*it));
			}
			vec.pb({(*it).f, i+1});
			se3.insert({(*it).f, i+1});
			continue;
		}
		if(arr[i]==3){
			if(se3.size()==0){
				cout<<-1;
				return 0;
			}
			auto it=se3.begin();
			auto u=(*it);
			
			if(se2.find(u)!=se2.end()){
				se2.erase(u);
				
			}
			se3.erase(u);
			vec.pb({pt, i+1});
			vec.pb({pt, u.s});
			se3.insert({pt, i+1});
			pt--;
			
		}
	}
	cout<<vec.size()<<endl;
	for(auto u:vec){
		cout<<u.f<<" "<<u.s<<endl;
	}
	return 0;
}