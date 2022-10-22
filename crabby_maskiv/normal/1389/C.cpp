#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
char a[N];
int main(){
	int i,j,k;
	int T;cin>>T;
	while(T--){
		cin>>(a+1);n=strlen(a+1);
		int ans=n;
		for(i=0;i<10;i++)
			for(j=0;j<10;j++){
				int cnt=0;
				for(k=1;k<=n;k++){
					if(((cnt&1)&&a[k]-'0'==j)||(!(cnt&1)&&a[k]-'0'==i))
						cnt++;
				}
				if(i!=j) cnt-=(cnt&1);
				ans=min(ans,n-cnt);
			}
		
		cout<<ans<<endl;
		for(i=1;i<=n;i++) a[i]=0;
	}
	return 0;
}