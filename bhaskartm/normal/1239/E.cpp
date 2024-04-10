#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int M=1300000;
bool dp[26][M];
bool dp2[26][M];
int par[26][M];
int t1, t2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	vector<int>v;
	for(int i=0; i<2*n; i++){
		int x;
		cin>>x;
		x++;
		v.pb(x);
		
	}
	int ans=0;
	sort(v.begin(), v.end());
	t1=v[0];
	t2=v[1];
	ans=v[0]+v[1];
	reverse(v.begin(), v.end());
	v.pop_back();
	v.pop_back();
	sort(v.begin(), v.end());
	
	dp[0][0]=1;
	
	for(int i=0; i<v.size(); i++){
		for(int j=n-2; j>=0; j--){
			for(int k=M; k>=0; k--){
				if(k+v[i]<M && dp[j][k] && !dp[j+1][k+v[i]]){
					dp[j+1][k+v[i]]=1;
					par[j+1][k+v[i]]=v[i];
				}
			}
		}
	}
	
	int tot=0;
	
	for(auto u:v){
		tot+=u;
	}
	
	vector<int>ab;
	
	for(int j=(tot/2); j>=0; j--){
		if(dp[n-1][j]){
			
			int num=n-1;
			int su=j;
			while(su!=0){
				
				ab.pb(par[num][su]);
				
				su-=par[num][su];
				num--;
			}
			break;
		}
	}
	
	
	
	
	
	int fin[2][n];
	fin[0][0]=t1;
	fin[1][n-1]=t2;
	sort(ab.begin(), ab.end());
	
	for(int i=1; i<n; i++){
		fin[0][i]=ab[i-1];
	}
	
	multiset<int>se;
	for(auto u:v){
		se.insert(u);
	}
	
	
	for(auto u:ab){
		
		se.erase(se.find(u));
	}
	
	int pt=n-2;
	for(auto u:se){
		fin[1][pt]=u;
		pt--;
	}
	for(int i=0; i<2; i++){
		for(int j=0; j<n; j++){
			cout<<fin[i][j]-1<<" ";
		}
		cout<<endl;
	}
	return 0;
}