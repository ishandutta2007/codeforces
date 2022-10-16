#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m;
string s[253],t[253];
int dp[2][2][2][65536];
void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>t[i];
	if(n<m)
		for(int i=0;i<n;i++)
			s[i]=t[i];
	else{
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				s[j]+=t[i][j];
		swap(n,m);
	}
	for(int i=0;i<m;i++)
		s[n]+='x';n++;
	dp[0][0][0][0]=1;
	bool nw=0;
	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++){
			nw^=1;
			memset(dp[nw],0,sizeof(dp[nw]));
			for(int k=0;k<(1<<n);k++)
				if(s[i][j]=='.')
					for(int tp=0;tp<2;tp++)
						for(int lst=0;lst<2;lst++){
							int tmp=tp;if(k&(1<<n-1))tmp=1;
							int newmsk=((k<<1)+tmp&(1<<n)-1);
							add(dp[nw][lst|tp][(lst|tmp)^1][newmsk],dp[nw^1][lst][0][k]);
							if(lst|tmp)
								add(dp[nw][lst|tp][1][newmsk],dp[nw^1][lst][1][k]);
						}
				else
					for(int tp=0;tp<2;tp++)
						for(int lst=0;lst<2;lst++)
							add(dp[nw][0][tp][(k<<1)&(1<<n)-1],dp[nw^1][lst][tp][k]);
		}
	int ans=0;
	for(int i=0;i<(1<<n);i++){
		add(ans,dp[nw][0][0][i]);
		add(ans,dp[nw][0][1][i]);
	}cout<<ans;
}