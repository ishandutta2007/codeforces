#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n;
char s[100005],_s[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s+1);
		for (int i=1;i<=n;i++)_s[i]=s[i];
		sort(_s+1,_s+1+n);
		int ans=0;
		for (int i=1;i<=n;i++)
			if (s[i]!=_s[i])ans++;
		cout<<ans<<endl;
	}
	return 0;
}