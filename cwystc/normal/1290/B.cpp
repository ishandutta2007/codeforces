#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
char s[500010];
int q,n,l,r,a[500010],f[200010][33];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n) a[i]=s[i]-'a'+1;
	FOR(i,1,n){
		FOR(j,1,26) f[i][j]=f[i-1][j];
		f[i][a[i]]++;
	}
	cin>>q;
	while (q--){
		getint(l),getint(r);
		if (f[r][a[l]]-f[l-1][a[l]]==r-l+1){
			if (l==r) puts("Yes"); else puts("No");
			continue;
		}
		if (a[l]!=a[r]){puts("Yes");continue;}
		int cnt=0;
		FOR(j,1,26)
			if (f[r][j]-f[l-1][j]>0) ++cnt;
		if (cnt>=3) puts("Yes"); else puts("No");
	}
	return 0;
}