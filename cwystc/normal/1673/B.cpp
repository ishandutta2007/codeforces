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
char s[1000010];
int T,n,f[200010][27],las[27];

void doit(){
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,0,25) f[0][i]=0;
	FOR(i,1,n){
		FOR(j,0,25) f[i][j]=f[i-1][j]+(s[i]-'a'==j);
	}
	FOR(j,0,25) las[j]=0;
	bool gg=0;
	FOR(i,1,n){
		if (las[s[i]-'a']!=0){
			FOR(j,0,25) if (f[n][j]>0 && f[i][j]-f[las[s[i]-'a']-1][j]==0) gg=1;
		}
		las[s[i]-'a']=i;
	}
	if (gg) puts("NO"); else puts("YES");
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}