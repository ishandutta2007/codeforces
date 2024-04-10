#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
vector<int> am[2*(int)1e5+1];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int in;
	for(int i=0;i<n;i++){
		cin>>in;
		int moves=0;
		while(in!=0){
			am[in].push_back(moves);
			in/=2;
			moves+=1;
		}
		am[in].push_back(moves);
	}
	int ans=INT_MAX;
	for(int i=0;i<=2*(int)1e5;i++){
		if(am[i].size()>=k){
			sort(am[i].begin(),am[i].end());
			int fin=0;
			for(int j=0;j<k;j++)fin+=am[i][j];
			ans=min(ans,fin);
		}
	}
	printf("%d\n",ans);
    return 0;
}