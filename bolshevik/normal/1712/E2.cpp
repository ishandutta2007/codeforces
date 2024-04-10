#include<cstdio>
#include<vector>
using namespace std;
const int o=2e5+10;
int T;long long b[o],ans[o];vector<pair<int,int> > chg[o],ask[o];vector<int> vec[o];
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<o;pos+=lowbit(pos)) b[pos]+=val;}
inline long long query(int pos){long long res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
int main(){
	scanf("%d",&T);
	for(int i=1,l,r;i<=T;++i) scanf("%d%d",&l,&r),ask[l].push_back(make_pair(r,i)),ans[i]=(r-l+1ll)*(r-l)*(r-l-1)/6;
	for(int i=1;i<o;++i){
		if(2*i%3==0&&2*i%4==0) chg[2*i/4].push_back(make_pair(i,1));
		if(2*i%3==0&&2*i%5==0) chg[2*i/5].push_back(make_pair(i,1));
	}
	for(int i=1;i<o;++i) for(int j=i*2;j<o;j+=i) vec[j].push_back(i);
	for(int i=1;i<o;++i) for(int j=0,sz=vec[i].size();j<sz;++j) chg[vec[i][j]].push_back(make_pair(i,sz-j-1));
	for(int i=o;--i;){
		for(int j=chg[i].size();j--;) modify(chg[i][j].first,chg[i][j].second);
		for(int j=ask[i].size();j--;) ans[ask[i][j].second]-=query(ask[i][j].first);	
	}
	for(int i=1;i<=T;++i) printf("%lld\n",ans[i]);
	return 0;
}