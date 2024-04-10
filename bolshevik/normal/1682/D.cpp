#include<cstdio>
#include<set>
using namespace std;
const int o=2e5+10;
int T,n,z,x,y,X;set<int> S1,S;char s[o];
int main(){
	for(scanf("%d",&T);T--;S.clear(),S1.clear()){
		scanf("%d%s",&n,s+1);z=0;
		for(int i=1;i<=n;++i) z+=(s[i]-=48);
		if((z&1)||!z){printf("NO\n");continue;}
		printf("YES\n");
		for(int i=1;i<=n;++i){
			S.insert(i);
			if(s[i]) S1.insert(i);
		}
		for(int u,v;S1.size()>2;){
			s[v=*S.upper_bound(u=*S1.begin())]^=1;
			printf("%d %d\n",u,v);
			S1.erase(u);S.erase(u);
			if(s[v]) S1.insert(v);
			else S1.erase(v);
		}
		X=x=*S1.begin();y=*++S1.begin();
		for(int i=x%n+1;i^y;i=i%n+1) if(S.find(i)!=S.end()) printf("%d %d\n",x,i),x=i;
		for(int i=y%n+1;i^X;i=i%n+1) if(S.find(i)!=S.end()) printf("%d %d\n",y,i),y=i;
		printf("%d %d\n",x,y);
	}
	return 0;
}