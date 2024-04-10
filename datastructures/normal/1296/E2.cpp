#include <iostream>
#include <cstdio>
using namespace std;
int n,a[200005][27],tot,ans[200005];
char s[200005];
int main(){
	cin>>n;
	scanf("%s",s+1);
	for (int i=0;i<26;i++)
		for (register int j=1;j<=n;j++){
			if (s[j]-'a'!=i)continue;
			register int col=1;
			while(a[j][col]==1)col++;
			ans[j]=col;
			tot=max(tot,col);
			for (register int k=j;k>=1;k--)
				if (a[k][col]==1)break;
				else a[k][col]=1;
		}
	cout<<tot<<endl;
	for (int i=1;i<=n;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}