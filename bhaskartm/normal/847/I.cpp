#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

#define f first
#define s second
#define pb push_back
#define endl '\n'

vector<pair<int, int>>v2;
int cnt[300][300];
int dis[300][300];
int po[30];
int n, m, qq, p;
char arr[300][300];

bool che(int i, int j){
	if(i>=0 && i<n && j>=0 && j<m && arr[i][j]!='*'){
		return 1;
	}
	return 0;
}





main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m>>qq>>p;
	
	v2.pb({1, 0});
	v2.pb({-1, 0});
	v2.pb({0, 1});
	v2.pb({0, -1});
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>arr[i][j];
		}
	}
	po[0]=1;
	for(int i=1; i<30; i++){
		po[i]=2*po[i-1];
	}
	for(int i=0; i<300; i++){
		for(int j=0; j<300; j++){
			dis[i][j]=1e9;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(arr[i][j]=='*' || arr[i][j]=='.'){
				continue;
			}
			
			int num=arr[i][j]-'A'+1;
			queue<pair<int, int>>q;
			dis[i][j]=0;
			q.push({i, j});
			vector<pair<int, int>>vec;
			vec.pb({i, j});
			while(!q.empty()){
				auto u=q.front();
				q.pop();
				int d=dis[u.f][u.s];
				
				if(d>25){
					break;
				}
				cnt[u.f][u.s]+=((num*qq)/po[d]);
				
				for(auto uu:v2){
					if(che(uu.f+u.f, uu.s+u.s) && dis[uu.f+u.f][uu.s+u.s]>1+d){
						
						dis[uu.f+u.f][uu.s+u.s]=1+d;
						vec.pb({uu.f+u.f, uu.s+u.s});
						q.push({uu.f+u.f, uu.s+u.s});
					}
				}
			}
			
			for(auto u:vec){
				dis[u.f][u.s]=1e9;
			}
		}
	}
	int ans=0;
	for(int i=0; i<300; i++){
		for(int j=0; j<300; j++){
			if(cnt[i][j]>p){
				ans++;
			}
		}
	}
	cout<<ans;
	
	return 0;
}