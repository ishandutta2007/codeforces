#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

int a[30][30],pw[60];

signed main()
{
	pw[0]=1;
	for(int i=1;i<60;i++) pw[i]=pw[i-1]*2ll;
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			if(i%2==0) a[i][j]=0;
			else a[i][j]=pw[i+j-1];
		}
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
		fflush(stdout);
	}
	int q;
	cin>>q;
	while(q--){
		int x;cin>>x;
		vector<pair<int,int> > v;
		v.push_back(make_pair(0,0));
		int nowx=0,nowy=0,cnt=0;
		while(!(nowx==n-1&&nowy==n-1)){
			if(a[nowx][nowy]==0){
				if(x&(1ll<<cnt)){
					nowx++;
					v.push_back(make_pair(nowx,nowy));
				}
				else{
					nowy++;
					v.push_back(make_pair(nowx,nowy));
				}
			}
			else{
				if(x&(1ll<<cnt)){
					nowy++;
					v.push_back(make_pair(nowx,nowy));
				}
				else{
					nowx++;
					v.push_back(make_pair(nowx,nowy));
				}
			}
			cnt++;
		}
		for(int i=0;i<v.size();i++){
			cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
			fflush(stdout);
		}
	} 
	return 0;
}