#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000000,DIG=10,inf=0x3f3f3f3f;
int need[DIG][DIG][DIG][DIG];
void init(){
	for(int i=0;i<=9;i++)for(int j=0;j<=9;j++)for(int k=0;k<=9;k++)for(int o=0;o<=9;o++){
		int mn=inf;
		for(int p=0;p<=9;p++)for(int q=0;q<=9;q++){
			int nw=(i+k*p+o*q)%10;
			if((nw+k)%10==j||(nw+o)%10==j)mn=min(mn,p+q);
		}
		need[i][j][k][o]=mn;
	}
}
int n;//
char s[N+5];
int cnt[DIG][DIG];
signed main(){
	init();
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<n;i++)cnt[s[i]^48][s[i+1]^48]++;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			int ans=0;
			for(int k=0;k<=9;k++)for(int o=0;o<=9;o++)
				ans+=cnt[k][o]*need[k][o][i][j];
			if(ans>=inf)cout<<"-1 ";
			else cout<<ans<<" ";
		}
		puts("");
	}
	return 0;
}