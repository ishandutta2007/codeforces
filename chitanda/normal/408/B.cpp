#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long

char ch;
int tot[27],ans=0,cx[27],ok[27];
int main(){
	ch=getchar();
	while(ch>'z' || ch<'a') ch=getchar();
	while(ch<='z'&&ch>='a') tot[ch-'a']++,ch=getchar();
	while(ch>'z' || ch<'a') ch=getchar();
	while(ch<='z'&&ch>='a') {
		if (tot[ch-'a']) ans++,tot[ch-'a']--,ok[ch-'a']=1;
		cx[ch-'a']=1;
		ch=getchar();
	}
	for(int i=0;i<26;i++)
		if (cx[i] && !ok[i]){
			printf("-1\n"); return 0;
		}
	if (ans) printf("%d\n",ans); else printf("-1\n");
	return 0;
}