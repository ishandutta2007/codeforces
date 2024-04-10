#include <bits/stdc++.h>
using namespace std;
void read(int &x){
    char ch=getchar();x=0;
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
    char ch=getchar();s="";
    for (;ch==' '||ch=='\n';ch=getchar());
    for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int dp[1000004][20],n,r,c;
string s[1000004];
int num[1000004],d[1000004];
int main(){
	read(n),read(r),read(c);
	for (int i=1;i<=n;i++){
		reads(s[i]);
		num[i]=s[i].size();
		d[i]=d[i-1]+num[i];
	}
	for (int i=1;i<=n;i++){
		if (num[i]>c){
			dp[i][0]=-1;
			continue;
		}
		int l=i-1,r=n+1;
		while (r>l+1){
			int mid=(l+r)/2;
			if (c>=mid-i+d[mid]-d[i-1]) l=mid;
			else r=mid; 
		}
		dp[i][0]=l;
	}
	for (int i=1;i<20;i++) for (int j=1;j<=n;j++){
		if (dp[j][i-1]==-1 || dp[j][i-1]==n){
			dp[j][i]=dp[j][i-1];
			continue;
		}
		if (dp[dp[j][i-1]+1][i-1]==-1){
			dp[j][i]=dp[j][i-1];
			continue;
		}
		dp[j][i]=dp[dp[j][i-1]+1][i-1];		
	}
	int ans=0,now=-1;
	for (int i=1;i<=n;i++){
		int res=i-1;
		if (dp[i][0]==-1) continue; 
		for (int j=0;j<20;j++) if((1<<j)&r){
			if (dp[res+1][j]==-1) break;
			res=dp[res+1][j];
			if (res==n) break;
		}
		if (res-i+1>ans){
			ans=res-i+1;
			now=i;
		}
	}
	if (now==-1) return 0;
	int cnt=num[now],tr=0,me=1;
	printf("%s",s[now].c_str());
	for (int i=now+1,j=1;j<ans;i++,j++){
		if (cnt+me+num[i]>c){
			tr++;
			puts("");
			cnt=num[i];
			me=1;
		}else{
			putchar(' ');
			cnt+=num[i];
			me++;
		}
		printf("%s",s[i].c_str());
	}
}