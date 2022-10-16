#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,ans;
char s[1000005];
signed main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for (int i=0;i<26;i++){
		int nows=0,len=0;
		for (int j=1;j<=n;j++){
			if (s[j]==(char)(i+'a'))len++;
			else{
				nows+=len/k;
				len=0;
			}
		}
		nows+=len/k;
		ans=max(ans,nows);
	}
	cout<<ans<<endl;
	return 0;
}