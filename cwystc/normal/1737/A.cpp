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
int n,k,cnt[555],T;
char s[555555],ans[555555];
void doit(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	FOR(i,0,100) cnt[i]=0;
	FOR(i,1,n) ++cnt[s[i]-'a'];
	int siz=n/k;
	FOR(i,1,k){
		int dao=-1;
		for (int j=0;j<siz;++j)
			if (cnt[j]>0){
				--cnt[j];
				dao=j;
			}
			else break;
		ans[i]='a'+dao+1;
	}
	FOR(i,1,k) putchar(ans[i]);
	puts("");
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
	return 0;
}