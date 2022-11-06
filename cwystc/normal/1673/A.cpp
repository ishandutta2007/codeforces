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
int T,n;
void doit(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	FOR(i,1,n) ans+=s[i]-'a'+1;
	int mn=min(s[1]-'a'+1,s[n]-'a'+1);
	if (n%2==0) printf("Alice %d\n",ans);
	else if (ans-mn>mn) printf("Alice %d\n",ans-mn-mn);
	else printf("Bob %d\n",mn+mn-ans);
}
int main(){
    
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}