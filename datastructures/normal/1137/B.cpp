#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
char s[500005],t[500005];
int cnt[2];
int kmp[500005];
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	int j=0;
	kmp[0]=-1;
	for (int i=2;i<=m;i++){
		while(j!=-1&&t[j+1]!=t[i])j=kmp[j];
		j++;
		if (j>0)kmp[i]=j;
	}
	for (int i=1;i<=n;i++)cnt[s[i]-'0']++;
	for (int i=1;i<=n;i++){
		int p;
		if (i<=m)p=i;
		else{
			if ((i-m)%(m-kmp[m])==0)p=m;
			else p=kmp[m]+(i-m)%(m-kmp[m]);
		}
		if (cnt[t[p]-'0']>0)putchar(t[p]),cnt[t[p]-'0']--;
		else putchar('0'+'1'-t[p]),cnt['1'-t[p]]--;
	}
	puts("");
	return 0;
}