#include<cstdio>
#include<iostream>
#include<set>
using namespace std;
const int o=1e5+10;const long long inf=1e11;
int T,n,a[o];long long ans,res=0;bool vis[o];char s[o],t[o];set<int> pos[26];set<int>::iterator iter;
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) a[pos]+=val;}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=a[pos];return res;}
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans==inf?-1:ans),res=0){
		scanf("%d%s%s",&n,s+1,t+1);ans=inf;
		for(int i=0;i<26;++i) pos[i].clear();
		for(int i=1;i<=n;++i) pos[s[i]-97].insert(i),a[i]=vis[i]=0;
		for(int i=1,j=1;j<=n;++i,++j){
			for(;vis[i];++i);
			for(int k=0;k<t[j]-97;++k) if((iter=pos[k].lower_bound(i))!=pos[k].end()) ans=min(ans,res+(*iter)-i-query(*iter)+query(i-1));
			if(s[i]^t[j]){
				if((iter=pos[t[j]-97].lower_bound(i))==pos[t[j]-97].end()) break;
				res+=(*iter)-i-query(*iter)+query(i-1);modify(*iter,1);vis[*iter]=1;pos[t[j]-97].erase(iter);--i;
			}
		}
	}
	return 0;
}