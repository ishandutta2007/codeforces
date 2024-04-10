#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int n,num[26],ans;
char s[100005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		num[s[1]-'a']++;
	}
	for (int i=0;i<26;i++){
		int a=num[i]/2;
		int b=num[i]-a;
		ans+=(a-1)*a/2;
		ans+=(b-1)*b/2;
	}
	cout<<ans<<endl;
	return 0;
}