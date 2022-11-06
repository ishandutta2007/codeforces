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
LL n,p,ans;
int main(){
	cin>>n>>p;
	while (++ans){
		n-=p;
		if (n<ans) break;
		LL t=n;
		int bit=0;
		while (t) bit+=t&1,t>>=1;
		if (bit<=ans) return cout<<ans<<endl,0;
	}
	puts("-1");
	return 0;
}