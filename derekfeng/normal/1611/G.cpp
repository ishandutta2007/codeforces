#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int n,m,ans;
char s[1000005];
set<int>st[2][1000005];
set<pii>lst;
vector<int>v[1000005],vec;
bool reach(pii a,pii b){
	if(a.fi<0||b.fi<0)return 1;
	return abs(a.fi-b.fi)>=abs(a.se-b.se);
}
void upd(int c){
	for(;;){
		vec.clear(),lst.clear();
		for(int i=0;i<n;i++)if(!st[c][i].empty()){
			int j=(*st[c][i].begin());
			vec.push_back(j),v[j].push_back(i);
		}
		if(vec.empty())break;
		sort(vec.begin(),vec.end());
		vec.erase(unique(vec.begin(),vec.end()),vec.end());
		ans++;
		for(auto x:vec){
			for(auto y:v[x]){
				pii L={-1,-1},R={-1,-1};
				auto it=lst.lower_bound({y,0});
				if(it!=lst.begin())L=*(--it);
				auto ti=lst.lower_bound({y,0});
				if(ti!=lst.end())R=*ti;
				if(reach(L,{y,x})&&reach({y,x},R)){
					lst.insert({y,x});
					st[c][y].erase(x);
				}
			}
			v[x].clear();
		}
	}
}
void sol(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		for(int j=0;j<m;j++)if(s[j]=='1')
			st[(i+j)&1][i].insert(j);
	}
	ans=0;
	upd(0),upd(1);
	printf("%d\n",ans);
}
int main(){
	int Tc;scanf("%d",&Tc);
	while(Tc--)sol();
}