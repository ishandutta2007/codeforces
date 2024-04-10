// Problem: D. Make a Power of Two
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
#define int long long
typedef long long ll;
const int N=62;
int t;
int len;char str[70];
string a[N];int dp[50][50];
signed main(){
	for(int i=0,now=1;i<N;i++,now*=2){
		int _=now;
		while(_)a[i]=(char)(_%10+'0')+a[i],_/=10;
		//cout<<a[i]<<endl;
	}
	read(t);;while(t--){
		cin>>str;
		len=strlen(str);int ans=len+1;
		for(int i=0;i<N;i++){
			memset(dp,0,sizeof dp);
			for(int j=0;j<len;j++)
				for(int k=0;k<a[i].size();k++){
					if(str[j]==a[i][k])if(dp[j][k]||k==0)
						dp[j+1][k+1]=1;
					dp[j+1][k+1]|=dp[j][k+1];
				}
			for(int j=1;j<=a[i].size();j++)if(dp[len][j])
			chkmn(ans,len+(int)a[i].size()-2*j);
		}
		write(ans);putchar('\n');
	}
}