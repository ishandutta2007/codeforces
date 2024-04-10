#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R 200000
#define inf (1ll*1e17)
#define sortall(x,y) sort((x).begin(),(x).end(),y)
#define pb push_back
int n,esum;
struct holiday{int l,r,c;};
bool cmp1(holiday a,holiday b){return a.l<b.l;}
bool cmp2(holiday a,holiday b){return a.r<b.r;}
vector<holiday> ho[R+1];
signed main(){
	scanf("%lld%lld",&n,&esum);
	for(int i=1;i<=n;i++){
		int x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		ho[y-x+1].pb((holiday){x,y,z});
	}
	int ans=inf;
	for(int i=1;i<esum;i++)if(esum&1||i!=esum/2&&ho[i].size()&&ho[esum-i].size()){
		sortall(ho[i],cmp1);sortall(ho[esum-i],cmp2);
		int mn=inf,now=0;
		for(int j=0;j<ho[i].size();j++){
			while(now<ho[esum-i].size()&&ho[esum-i][now].r<ho[i][j].l)
				mn=min(mn,ho[esum-i][now++].c);
//			cout<<"i="<<i<<" j="<<j<<" now="<<now<<"\n";
			ans=min(ans,mn+ho[i][j].c);
		}
	}
	if(!(esum&1)&&ho[esum>>1].size()){
		esum>>=1;
		sortall(ho[esum],cmp1);sortall(ho[0]=ho[esum],cmp2);
		int mn=inf,now=0;
		for(int i=0;i<ho[esum].size();i++){
			while(now<ho[0].size()&&ho[0][now].r<ho[esum][i].l)
				mn=min(mn,ho[0][now++].c);
			ans=min(ans,mn+ho[esum][i].c);
		}
	}
	printf(ans==inf?"-1":"%lld",ans);
	return 0;
}
/*1
4 5
1 3 4
1 2 5
5 6 1
1 2 4
*/
/*2
3 2
4 6 3
2 4 1
3 5 4
*/