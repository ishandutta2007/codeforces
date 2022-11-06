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

int x[1000100],y[1000010],n,h,ans[1000010];
bool u[1000010];

int main(){
	cin>>n;
	FOR(i,1,n) scanf("%d%d",&x[i],&y[i]);
	u[1]=1;
	ans[1]=1;
	FOR(i,2,n){
		int h=ans[i-1];
		LL d=-1;
		int id=0;
		FOR(j,1,n) if (!u[j]){
			if (1ll*(x[j]-x[h])*(x[j]-x[h])+1ll*(y[j]-y[h])*(y[j]-y[h])>d){
				d=1ll*(x[j]-x[h])*(x[j]-x[h])+1ll*(y[j]-y[h])*(y[j]-y[h]);
				id=j;
			}
		}
		ans[i]=id;
		u[id]=1;

	}
	FOR(i,1,n) printf("%d ",ans[i]);
    return 0;
}