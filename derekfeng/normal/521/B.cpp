#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
map<pii,int>mp;
vector<int>g[100004],rg[100004];
int m,X[100004],Y[100004];
bool vis[100004];
int w(int x){
	if(vis[x])return 114;
	int num=0;
	for(auto to:g[x])if(!vis[to])num++;
	return num;
}
bool check(int x){
	if(vis[x])return 0;
	bool ok=1;
	for(auto to:rg[x])if(w(to)<2)ok=0;
	return ok;
}
long long ans=0;
const int M=1e9+9;
int main(){
	cin>>m;
	for(int i=0;i<m;i++)cin>>X[i]>>Y[i],mp[mkp(X[i],Y[i])]=i+1;
	for(int i=0;i<m;i++)
		for(int j=-1;j<=1;j++)
			if(mp[mkp(X[i]+j,Y[i]-1)]){
				int x=mp[mkp(X[i]+j,Y[i]-1)]-1;
				g[i].push_back(x); 
				rg[x].push_back(i); 
			}
	set<int>st;
	for(int i=0;i<m;i++)if(check(i))st.insert(i);
	for(int i=0;i<m;i++){
		int x;
		if(i%2==0){
			auto it=st.end();it--;
			x=*it;
			st.erase(it); 
		}else{
			auto it=st.begin();
			x=*it;
			st.erase(it); 
		}
		ans=(ans*m+x)%M;
		vis[x]=1;
		for(auto y:rg[x])for(auto z:g[y])if(!check(z)&&!vis[z]&&st.find(z)!=st.end())st.erase(st.find(z));
		for(auto y:g[x])if(check(y))st.insert(y);
	}
	cout<<ans;
}