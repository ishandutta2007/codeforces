#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int q,n1,n2;
char s[1000005],t[1000005];
signed main(){
	cin>>q;
	while(q--){
		scanf("%s",s+1);
		scanf("%s",t+1);
		n1=strlen(s+1);
		n2=strlen(t+1);
		int a=1,b=1,flag=1;
		while(a<=n1&&b<=n2){
			if (s[a]!=t[b]){
				flag=0;
				break;
			}
			if (s[a]!=s[a+1]){
				while(s[a]==t[b])b++;
				a++;
				continue;
			}
			a++,b++;
		}
		if (a<=n1||b<=n2)flag=0;
		if (flag==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}