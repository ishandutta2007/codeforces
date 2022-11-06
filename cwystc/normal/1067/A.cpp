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
const int MO=998244353;
int n,a[500010],f[100010][210][2],g[100010][210][2],ans;
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]);
	if (a[1]==-1){
		FOR(i,1,200) f[1][i][1]=1;
	}
	else f[1][a[1]][1]=1;
	FOR(k,1,200){
		(g[1][k][0]=g[1][k-1][0]+f[1][k][0])%=MO;
		(g[1][k][1]=g[1][k-1][1]+f[1][k][1])%=MO;
	}
	FOR(i,2,n){
		if (a[i]!=-1){
			FOR(j,1,200){
				if (a[i]<=j && j<=a[i]) (f[i][a[i]][0]+=f[i-1][j][1])%=MO;
				if (a[i]<=j) (f[i][a[i]][0]+=f[i-1][j][0])%=MO;
				if (a[i]>j) (f[i][a[i]][1]+=f[i-1][j][0])%=MO;
				if (a[i]>=j && a[i]>j) (f[i][a[i]][1]+=f[i-1][j][1])%=MO;
			}
		}
		else{
			FOR(k,1,200){
				(f[i][k][0]+=f[i-1][k][1])%=MO;
			//	f[i][k][0]+=f[i-1][>=k][0]
				(f[i][k][0]+=(g[i-1][200][0]-g[i-1][k-1][0])%MO)%=MO;
				(f[i][k][1]+=g[i-1][k-1][0])%=MO;
				(f[i][k][1]+=g[i-1][k-1][1])%=MO;
			}
		}
		FOR(k,1,200){
			(g[i][k][0]=g[i][k-1][0]+f[i][k][0])%=MO;
			(g[i][k][1]=g[i][k-1][1]+f[i][k][1])%=MO;
		}
	}
	FOR(k,1,200) (ans+=f[n][k][0])%=MO;
	ans=(ans%MO+MO)%MO;
	cout<<ans<<endl;
	return 0;
}