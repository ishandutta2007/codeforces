#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,k,a,b,c,tot;
char s[1005],ans[1005];
signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	cin>>k;
	for (int i=1;i<=n;i++){
		if (s[i]=='?')a++;
		else if (s[i]=='*')b++;
		else c++;
	} 
	if (c<k&&b==0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if (c-(a+b)>k){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if (c<k){
		int flag=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='?')continue;
			if (s[i]=='*'){
				if (flag!=0)continue;
				flag=1;
				for (int j=1;j<=k-c;j++)ans[++tot]=s[i-1];
			}
			else ans[++tot]=s[i];
		}
		for (int i=1;i<=tot;i++)cout<<ans[i];cout<<endl;
		return 0; 
	}
	else{
		int cnt=c-k;
		for (int i=1;i<=n;i++){
			if (s[i]=='?'||s[i]=='*')continue;
			if (s[i+1]=='?'||s[i+1]=='*'){
				if (cnt>0){
					cnt--;
					continue;
				}
				else ans[++tot]=s[i];
			}
			else ans[++tot]=s[i];
		}
		for (int i=1;i<=tot;i++)cout<<ans[i];cout<<endl;
		return 0;
	}
	return 0;
}