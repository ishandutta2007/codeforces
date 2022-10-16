#include <iostream>
#include <cstdio>
using namespace std;
int t,n,lcp[5005][5005],f[5005];
char s[5005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s+1);
		for (int i=n;i>=1;i--)
			for (int j=n;j>=1;j--)
				if (s[i]==s[j])lcp[i][j]=1+lcp[i+1][j+1];
				else lcp[i][j]=0;
		f[1]=n;
		for (int i=2;i<=n;i++){
			f[i]=n-i+1;
			for (int j=1;j<i;j++){
				int qwq=lcp[i][j];
				if (s[i+qwq]>s[j+qwq])f[i]=max(f[i],f[j]+n-(i+qwq)+1);
			}
		}
		int ans=0;
		for (int i=1;i<=n;i++)ans=max(ans,f[i]);
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				lcp[i][j]=0;
		for (int i=1;i<=n;i++)f[i]=0;
	}
	return 0;
}