#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <queue>
using namespace std;
char s[100005];
int n,flag; 
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	if (n==1&&s[1]=='0'){
		cout<<0<<endl;
		return 0;
	}
	for (int i=n;i>1;i--)
		if (s[i]=='1')flag=1;
	if (flag==0){
		if (n%2==1)cout<<(n-1)/2<<endl;
		else cout<<(n-1)/2+1<<endl;
	}
	else cout<<(n-1)/2+1<<endl;
	return 0;
}