#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
char s[1000005];
int n,k;
signed main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++){
		if (k==0)continue;
		if (i==1&&n!=1){
			if (s[i]=='1')continue;
			s[i]='1',k--;
		}
		else{
			if (s[i]=='0')continue;
			s[i]='0',k--;
		}
	}
	for (int i=1;i<=n;i++)printf("%c",s[i]);
	cout<<endl;
	return 0;
}