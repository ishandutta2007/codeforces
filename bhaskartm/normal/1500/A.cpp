#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=5000005;
const int M=2500005;
pair<int, int>val[N];
vector<vector<int>>vec;
int n;
int arr[M];
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vec.resize(M);
	for(int i=1; i<=n; i++){
		int x;
		cin>>x;
		arr[i]=x;
		vec[x].pb(i);
	}
	int ind1=-1;
	int ind2=-1;
	for(int i=1; i<M; i++){
		if((int(vec[i].size()))>=4){
			cout<<"YES"<<endl;
			for(int j=0; j<4; j++){
				cout<<vec[i][j]<<" ";
			}
			return 0;
		}
		if((int(vec[i].size()))>=2 && ind1==-1){
			ind1=i;
			continue;
		}
		if((int(vec[i].size()))>=2 && ind1!=-1){
			ind2=i;
			continue;
		}
	}
	if(ind1!=-1 && ind2!=-1){
		cout<<"YES"<<endl;
		cout<<vec[ind1][0]<<" "<<vec[ind2][0]<<" "<<vec[ind1][1]<<" "<<vec[ind2][1]<<endl;
		return 0;
	}
	if(ind1!=-1){
		val[2*ind1]={vec[ind1][0], vec[ind1][1]};
		arr[vec[ind1][0]]=0;
		int sz=vec[ind1].size();
		if(sz==3){
			arr[vec[ind1][1]]=0;
		}
	}
	
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(arr[i]==arr[j] || arr[i]==0 || arr[j]==0){
				continue;
			}
			if(val[arr[i]+arr[j]].f!=0){
				cout<<"YES"<<endl;
				cout<<val[arr[i]+arr[j]].f<<" "<<val[arr[i]+arr[j]].s<<" "<<i<<" "<<j<<endl;
				return 0;
			}
			else{
				val[arr[i]+arr[j]]={i, j};
			}
		}
	}
	cout<<"NO"<<endl;
	
	
	return 0;
}