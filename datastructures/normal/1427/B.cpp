#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,k;
char s[1000005];
int tot,c[1000005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>k;
		scanf("%s",s+1);
		int ans=0,qwq=0;
		tot=0;
		for (int i=1;i<=n;i++){
			if (s[i]=='W'){
				ans++;
				if (i>1&&s[i-1]=='W')ans++;
				continue;
			}
			int j=i;
			while(j<=n&&s[j]=='L')j++;
			j--;
			qwq+=j-i+1;
			if (i!=1&&j!=n)c[++tot]=j-i+1;
			i=j;
		}
		if (qwq<=k){
			cout<<2*n-1<<endl;
			continue;
		}
		if (qwq==n){
			cout<<max(0,2*k-1)<<endl;
			continue;
		}
		ans+=2*k;
		sort(c+1,c+tot+1);
		for (int i=1;i<=tot;i++)
			if (k>=c[i])k-=c[i],ans++;
		cout<<ans<<endl;
	}
	return 0;
}