#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,k,last,nxt[200005];
char s[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		scanf("%s",s+1);
		int last=-1000000,ans=0;
		nxt[n+1]=1000000;
		for (int i=n;i>=1;i--)
			if (s[i]=='1')nxt[i]=i;
			else nxt[i]=nxt[i+1];
		for (int i=1;i<=n;i++){
			if (s[i]=='0'&&i-last>=k+1&&nxt[i]-i>=k+1){
				s[i]='1';
				ans++;
				last=i;
			}
			if (s[i]=='1')last=i; 
		}
		cout<<ans<<endl; 
	}
	return 0;
}