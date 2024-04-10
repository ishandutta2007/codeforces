#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#define int long long
using namespace std;
int n;
char s[100005];
signed main(){
	cin>>n;
	scanf("%s",s+1);
	sort(s+1,s+1+n);
	for (int i=1;i<=n;i++)printf("%c",s[i]);
	cout<<endl;
	return 0;
}