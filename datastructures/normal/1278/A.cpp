#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int q;
char s[100005],t[100005];
int book1[105],book2[105],book3[105];
int main(){
	cin>>q;
	while(q--){
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int fg=0;
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		for (register int i=1;i<=n;i++)book1[s[i]-'a']++;
		for (register int i=1;i<=m;i++)book2[t[i]-'a']++;
		for (register int i=1;i<=m-n+1;i++){
			memset(book3,0,sizeof(book3));
			for (register int j=1;j<=n;j++)
				book3[t[i+j-1]-'a']++;
			int s=1;
			for (register int j=0;j<26;j++)
				if (book3[j]!=book1[j])s=0;
			if (s==1)fg=1;
		}
		for (int i=0;i<26;i++)
			if (book1[i]>book2[i])fg=0;
		if (fg==1)puts("YES");
		else puts("NO");
	}
	return 0;
}