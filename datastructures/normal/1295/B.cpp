#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int t;
char s[100005];
int n,x,p[100005];
signed main(){
	cin>>t;
	while(t--){
		cin>>n>>x;
		scanf("%s",s+1);
		p[0]=0;
		for (int i=1;i<=n;i++)
			if (s[i]=='0')p[i]=p[i-1]+1;
			else p[i]=p[i-1]-1;
		int delta=p[n],ans=0;
		if (x==0)ans++;
		if (delta==0){
			for (int i=1;i<=n;i++)	
				if (p[i]==x)ans++;
			if (ans>0)cout<<-1<<endl;
			else cout<<0<<endl;
		}
		else{
			for (int i=1;i<=n;i++){
				int num=x-p[i];
				if (num%delta!=0)continue;
				if (num/delta<0)continue;
				ans++;
			}
			cout<<ans<<endl;
		}
	}
}