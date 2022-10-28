#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
int a[300001];
int n;
int mini[300005][20];
int gc[300005][20];
int logg[300005];

vector<int>pos;
bool f(int num){
	int j=logg[num];
	bool b=0;
	for(int i=0; i<=n-num; i++){
		if(min(mini[i][j], mini[i+num-(1<<j)][j])==__gcd(gc[i][j], gc[i+num-(1<<j)][j])){
			b=1;
			pos.push_back(i);
		}
	}
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	logg[1]=0;
	for(int i=2; i<=300000; i++){
		logg[i]=1+logg[(i/2)];
	}
	for(int i=0; i<n; i++){
		mini[i][0]=a[i];
		gc[i][0]=a[i];
	}
	for(int j=1; j<20; j++){
		for(int i=0; i+(1<<j)<=n; i++){
			mini[i][j]=min(mini[i][j-1], mini[i+(1<<(j-1))][j-1]);
			gc[i][j]=__gcd(gc[i][j-1], gc[i+(1<<(j-1))][j-1]);
		}
	}
	int lo=1;
	int hi=n;
	int ans=-1;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		if(f(mid)){
			ans=mid;
			lo=mid+1;
			pos.clear();
		}
		else{
			hi=mid-1;
		}
	}
	f(ans);
	cout<<pos.size()<<" "<<ans-1<<endl;
	for(auto u:pos){
		cout<<u+1<<" ";
	}
	
	return 0;
}