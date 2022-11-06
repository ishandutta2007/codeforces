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
int n,a[500010],b[55],ans;
void ins(int x){
	FORD(i,29,0)
		if ((x>>i)&1){
			if (b[i]) x^=b[i];
			else{
				b[i]=x;
				return;
			}
		}
}
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]),a[i]^=a[i-1];
	if (a[n]==0) return puts("-1"),0;
	FORD(i,n,1) ins(a[i]);
	FOR(i,0,29) if (b[i]) ++ans;
	cout<<ans<<endl;
	return 0;
}