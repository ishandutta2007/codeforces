#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,f[5005][5005],book[5005][5005];
int qwq;
char s[5005][5005],ans[10005];
int main(){
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	memset(f,0x7f,sizeof(f));
	f[0][1]=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			f[i][j]=min(f[i][j-1],f[i-1][j]);
			if (s[i][j]!='a')f[i][j]++;
			if (f[i][j]<=k)qwq=max(qwq,i+j-1);
		}
	for (int i=1;i<=qwq;i++)ans[i]='a';
	for (int i=1;i<=n;i++){
		if (qwq+1-i>=1&&qwq+1-i<=n)
			if (f[i][qwq+1-i]<=k)book[i][qwq+1-i]=1;
	}
	book[0][1]=book[1][0]=1;
	for (int i=qwq+1;i<=2*n-1;i++){
		for (int j=0;j<26;j++){
			int fg=0;
			for (int k=1;k<=n;k++)
				if (i+1-k>=1&&i+1-k<=n&&s[k][i+1-k]-'a'<=j&&(book[k-1][i+1-k]==1||book[k][i-k]==1))fg=1;
			if (fg==1){
				ans[i]=j+'a';
				for (int k=1;k<=n;k++)
					if (i+1-k>=1&&i+1-k<=n&&s[k][i+1-k]-'a'<=j&&(book[k-1][i+1-k]==1||book[k][i-k]==1))book[k][i+1-k]=1;
				break;
			}
		}
	}
	for (int i=1;i<=2*n-1;i++)putchar(ans[i]);
	puts("");
	return 0;
}