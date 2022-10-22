#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
const int o=1e5+10;
int T,n,a[o],s[o],f[o];map<int,int> mp;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",f[n]),mp.clear()){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		mp[0]=-1;
		for(int i=1;i<=n;++i){
			f[i]=f[i-1]+!!a[i];
			if(mp.find(s[i])!=mp.end()) f[i]=min(f[i],mp[s[i]]+i),mp[s[i]]=min(mp[s[i]],f[i]-i-1);
			else mp[s[i]]=f[i]-i-1;
		}
	}
	return 0;
}