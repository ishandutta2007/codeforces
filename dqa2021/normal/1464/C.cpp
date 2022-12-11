#include<cstdio>
#include<algorithm>
#include<cctype>
#include<iostream>
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
typedef long long ll;

int n; ll T;
char s[100010];
int w[150];
int c[150];
int main()
{
	for (int i='a';i<='z';i++) w[i]=1<<(i-'a');
	cin>>n>>T;
	scanf("%s",s+1);
	T-=w[s[n]]-w[s[n-1]];
	ll S=0;
	for (int i=1;i<=n-2;i++) S+=w[s[i]],c[s[i]]++;
	if (S<T) return puts("NO"),0;
	S-=T;
	if (S&1) return puts("NO"),0;
	S>>=1;
	int tot=0;
	for (int i='a';i<='z';i++,tot>>=1){
		tot+=c[i];
		if (S>>(i-'a')&1){
			if (!tot) return puts("NO"),0;
			tot--;
		}
	}
	puts("YES");
	return 0;
}