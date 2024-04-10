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
int n,stk[1000010],x,top;
LL ans;
int main(){
	cin>>n;
	FOR(i,1,n){
		getint(x);
		if (top && stk[top]%2==x%2) ans+=(stk[top]+x)/2,--top;
		else stk[++top]=x;
	}
	FOR(i,1,top) ans+=stk[i]/2;
	cout<<ans<<endl;
	return 0;
}