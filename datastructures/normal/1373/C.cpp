#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#define int long long
using namespace std;
int t,n;
char s[1000005];
signed main(){
	cin>>t;
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1); 
		int now=0,ans=0;
		map <int,int>c;
		for (int i=1;i<=n;i++){
			if (s[i]=='+')now++;
			else now--;
			if (c[now]==0)c[now]=i; 
		}
		for (int i=0;i<=n;i++)
			if (c[-i-1]==0){
				ans+=n;
				break;
			}
			else ans+=c[-i-1];
		cout<<ans<<endl;
	}
	return 0;
}