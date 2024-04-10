#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int T,n,c,ans;map<int,int> mp;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans),ans=0,mp.clear()){
		scanf("%d%d",&n,&c);
		for(int i=1,a;i<=n;++i) scanf("%d",&a),++mp[a];
		for(map<int,int>::iterator iter=mp.begin();iter!=mp.end();++iter) ans+=min(c,(*iter).second);
	}
	return 0;
}