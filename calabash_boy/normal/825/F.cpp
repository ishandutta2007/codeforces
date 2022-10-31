#include<bits/stdc++.h>
using namespace std;
#define MAXN 8005
#define INF 2147483640
char s[MAXN];
int n;
int dp[MAXN];
int nxt[MAXN];
int nums (int a){
	int ans = 0;
	while (a)ans++,a/=10;
	return ans;
}
void kmp(char ss[]){
	memset(nxt,sizeof(nxt),0);
	int len = strlen(ss+1);
	for (int i=2;i<=len;i++){
		nxt[i]=nxt[i-1];
		while (nxt[i]&&ss[i]!=ss[nxt[i]+1])nxt[i]=nxt[nxt[i]];
		nxt[i]+=(ss[i]==ss[nxt[i]+1]); 
	}
//	cout<<"finish"<<endl;
}
int main(){
	scanf("%s",s+1);
	n = strlen(s+1);
	for (int i=1;i<=n;i++){
		dp[i]=INF;
	}
//	cout<<n<<endl;
	for (int i=0;i<=n;i++){
		kmp(s+i);
		for (int j=i+1;j<=n;j++){
			int temp = j-i-nxt[j-i];
			int recyTime = (j-i)%temp==0?(j-i)/temp:1;
			dp[j] = min(dp[j],dp[i]+(j-i)/recyTime+nums(recyTime));
		}
	}	
	cout<<dp[n]<<endl;
	return 0;
}