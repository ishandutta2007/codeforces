#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int x,y,z,w;
	cin >> x >> y >> z;
	int n=x+y+z;
	int ind[n];
	loop(x){
		cin >> w;
		ind[w-1]=0;
	}
	loop(y){
		cin >> w;
		ind[w-1]=1;
	}
	loop(z){
		cin >> w;
		ind[w-1]=2;
	}
	vector<int> lis;
	loop(n){
		if(lis.empty()) lis.push_back(ind[i]);
		else if(ind[i]>=*(lis.end()-1)) lis.push_back(ind[i]);
		else *upper_bound(lis.begin(),lis.end(),ind[i])=ind[i];
	}
	cout << n-lis.size() << "\n";
	return 0;
}