#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> occ[300005];
int S[300005];
bool bo[300005];
void solve(){
	int n,m,i,x,y,j,k,c,tot=0;
	scanf("%d%d",&n,&m);
	vector<int> a(n);
	map<int,int>M;
	vector<pair<int,int>>badpairs;
	for(i=0;i<n;++i){
		scanf("%d",&a[i]);
		++M[a[i]];
		bo[i]=0;
		occ[i+1].clear();
	}
	badpairs.reserve(m*2);
	for(i=0;i<m;++i){
		scanf("%d%d",&x,&y);
		badpairs.push_back(make_pair(x,y));
		badpairs.push_back(make_pair(y,x));
	}
	sort(badpairs.begin(),badpairs.end());
	sort(a.begin(),a.end());
	for(i=0;i<n;++i){
		if(i&&a[i]==a[i-1])continue;
		occ[M[a[i]]].push_back(a[i]);
		bo[M[a[i]]]=1;
	}
	for(i=1;i<=n;++i){
		if(bo[i])S[++tot]=i;
	}
	for(i=1;i<=tot;++i){
		sort(occ[S[i]].begin(),occ[S[i]].end());
		reverse(occ[S[i]].begin(),occ[S[i]].end());
	}
	ll ans=0;//int icnt=0;
	for(i=1;i<=tot;++i){
		for(j=0;j<occ[S[i]].size();++j){
			x=occ[S[i]][j];
			for(k=1;k<=i;++k){
				for(auto y:occ[S[k]]){
					//++icnt;
					if(x!=y && !binary_search(badpairs.begin(),badpairs.end(),make_pair(x,y))){
						ans=max(ans,1LL*(S[i]+S[k])*(x+y));
						break;
					}
				}
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	//freopen("10.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}