#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
const int N=4e6+10;
int n,m;
int a[N],b[N];
int ans;
int l,r;
vector<int>G[N];
vector<int>p[N];
void sp(int bit){
	int ll=r+1,rr=r;
	for(int i=l;i<=r;i++){
		int x=0;
		for(int j=0;j<G[i].size();j++){
			if(G[i][j]>>bit&1)x++;
		}
		if(x==0||x==G[i].size()){
			rr++;
			G[rr].clear();
			p[rr].clear();
			for(int j=0;j<G[i].size();j++){
				G[rr].PB(G[i][j]);
				p[rr].PB(p[i][j]);
			}
		}
		else{
			rr+=2;
			G[rr].clear();
			G[rr-1].clear();
			p[rr].clear();
			p[rr-1].clear();
			for(int j=0;j<G[i].size();j++){
				if(G[i][j]>>bit&1)G[rr-1].PB(G[i][j]);
				else G[rr].PB(G[i][j]);
				if(p[i][j]>>bit&1)p[rr].PB(p[i][j]);
				else p[rr-1].PB(p[i][j]);
			}	
		}
		
	}
	l=ll,r=rr;
}
bool check(int bit){
	for(int i=l;i<=r;i++){
		int x=0,y=0;
		for(int j=0;j<G[i].size();j++){
			if(G[i][j]>>bit&1)x++;
			if(p[i][j]>>bit&1)y++;
		}
		if(x+y!=G[i].size())return 0;
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	G[1].clear();
	p[1].clear();
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		G[1].PB(a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		p[1].PB(b[i]);
	}
	l=r=1;
	ans=0;
	for(int i=29;i>=0;i--){
		if(check(i)){
			ans+=(1<<i);
			sp(i);
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}