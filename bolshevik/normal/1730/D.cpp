#include<cstdio>
#include<map>
#include<utility>
using namespace std;
const int o=2e5+10;
int T,n;char s[o],t[o];map<pair<int,int>,int> mp;
inline void chk(){
	int a=0;
	for(map<pair<int,int>,int>::iterator iter=mp.begin();iter!=mp.end();++iter) if((*iter).second&1){
		if((*iter).first.first!=(*iter).first.second){printf("NO\n");return;}
		else ++a;
	}
	if(a>(n&1)) printf("NO\n");
	else printf("YES\n");
}
int main(){
	for(scanf("%d",&T);T--;chk(),mp.clear()){
		scanf("%d%s%s",&n,s+1,t+1);
		for(int i=1,j=n;i<=n;++i,--j)
			if(s[i]<t[j]) ++mp[make_pair(s[i],t[j])];
			else ++mp[make_pair(t[j],s[i])];
	}
	return 0;
}