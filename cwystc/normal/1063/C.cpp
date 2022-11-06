#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
int n,l,r,o,tp,TP;
char s[500010];
int main(){
	cin>>n;
	puts("0 1");
	fflush(stdout);
	scanf("%s",s);
	if (s[0]=='b') tp=0;
	else tp=1;
	--n;
	l=1,r=999999999;
	while (n--){
		o=(l+r)/2;
		printf("%d 1\n",o);
		fflush(stdout);
		scanf("%s",s);
		if (s[0]=='b') TP=0;
		else TP=1;
		if (tp==TP){
			l=o+1;
		}
		else r=o-1;
	}
	printf("%d %d %d %d\n",l-1,0,r+1,2);
	return 0;
}