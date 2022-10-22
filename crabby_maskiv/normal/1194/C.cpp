#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int l1,l2,l3;
string s,t,a;
int cnt[200];
int dp[N][N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;
	cin>>T;
	while(T--){
		cin>>s>>t>>a;
		l1=s.length();l2=t.length();l3=a.length();
		s=" "+s;t=" "+t;a=" "+a;
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		for(i=1;i<=l3;i++) cnt[a[i]]++;
		for(i=1;i<=l1;i++) cnt[s[i]]++;
		for(i=1;i<=l2;i++) cnt[t[i]]--;
		for(i='a';i<='z';i++){
			if(cnt[i]<0){
				cout<<"NO"<<endl;
				break;
			}
		}
		if(i<='z') continue;
		for(i=0;i<=l2;i++) dp[i][0]=1;
		for(i=1;i<=l2;i++){
			for(j=1;j<=l1;j++){
				for(int k=0;k<i;k++)
					if(dp[k][j-1]&&t[i]==s[j])
						dp[i][j]=1;
			}
		}
		for(i=l1;i<=l2;i++){
			if(dp[i][l1]){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(i>l2) cout<<"NO"<<endl;
	}
	return 0;
}