#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
char s[300005];
int n,ans[300005],sum[300005],now;
inline bool check(){
	int now=0;
	for (int i=1;i<=n;i++){
		now+=ans[i];
		if (now<0)return 0;
		if (now==0&&i!=n)return 0;
	}
	if (now!=0)return 0;
	return 1;
}
signed main(){
	cin>>n;
	scanf("%s",s+1);
	for (int i=n;i>=1;i--)
		if (s[i]==')'||s[i]=='?')sum[i]=sum[i+1]+1;
		else sum[i]=sum[i+1]-1;
	for (int i=1;i<=n;i++){
		if (s[i]=='('){
			now++;
			ans[i]=1;
			continue;
		}
		if (s[i]==')'){
			now--;
			ans[i]=-1;
			continue;
		}
		if (now+1>sum[i+1])ans[i]=-1,now--;
		else ans[i]=1,now++;
	}
	if (check()){
		for (int i=1;i<=n;i++)
			if (ans[i]==1)printf("(");
			else printf(")");
	}
	else cout<<":("<<endl;
	return 0;
}