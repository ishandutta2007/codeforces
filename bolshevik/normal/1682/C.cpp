#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int T,n,ans;map<int,int> mp;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",(ans+1)/2),ans=0,mp.clear()){
		scanf("%d",&n);
		for(int i;n--;++mp[i]) scanf("%d",&i);
		for(map<int,int>::iterator iter=mp.begin();iter!=mp.end();++iter) ans+=min(2,(*iter).second);
	}
	return 0;
}