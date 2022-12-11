#include<bits/stdc++.h>
using namespace std;
char s[233333],p[233333]; int n,ans;
int main(){
	int t;scanf("%d",&t);while(t--){
		scanf("%d%s",&n,s);
		memcpy(p,s,n*sizeof('c'));
		sort(p,p+n);
		for(int i=0;i<n;++i)ans+=s[i]!=p[i];
		printf("%d\n",ans);ans=0;
	}
}