#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int tt,n,book[105][2];
char s[105],t[105];
signed main(){
	cin>>tt;
	while(tt--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1);
		int flag=0;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (s[i]==t[j])flag=1;
		if (flag==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}