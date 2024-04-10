#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
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
int n,a[500010];
LL ans;
int main(){
	scanf("%d",&n);
	FOR(i,1,n+n) getint(a[i]);
	sort(a+1,a+n+n+1);
	ans=1ll*(a[n]-a[1])*(a[n+n]-a[n+1]);
	FOR(i,0,n) ans=min(ans,1ll*(a[n+n]-a[1])*(a[i+n]-a[i+1]));
	cout<<ans<<endl;
    return 0;
}