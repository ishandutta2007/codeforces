#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int n; char s[210];
int c[26];
void init(){
	
}
void solve(){
	n=read(); scanf("%s",s+1);
	for (int i=0;i<26;i++) c[i]=0;
	for (int i=1;i<=n;i++) c[s[i]-'a']++;
	while (c['r'-'a']) c['r'-'a']--,putchar('r');
	for (int i=0;i<26;i++) if (i+'a'!='r'){
		while (c[i]) c[i]--,putchar('a'+i);
	}
	puts("");
}
int main()
{
	//check
	for (int T=read();T--;) init(),solve();
	return 0;
}