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

int n,T,ts;
LL k,a[500010],b[500010],g,tmp[500010];

void doit(){
	cin>>n>>k;
	FOR(i,1,n) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	FOR(i,2,n) b[i]=2ll*(a[i]-a[i-1]);
	g=b[2];
	FOR(i,3,n) g=__gcd(b[i],g);
	ts=0;
	FOR(i,1,n){
		if (a[i]==k){puts("YES");return;}
		tmp[++ts]=a[i];
		tmp[++ts]=a[1]*2-a[i];
	}
	FOR(i,1,ts){
		if ((k-tmp[i])%g==0){puts("YES");return;}

	}
	puts("NO");

}
int main(){
	cin>>T;
	while (T--) doit();
    return 0;
}