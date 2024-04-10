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
const int MO=1e9+7;
LL ans;
int n,m,a[2222][2222],f[2222][2222][2],g[2222][2222][2],you[2222][2222],xia[2222][2222];
char s[500010];
int main(){
	cin>>n>>m;
	FOR(i,1,n){
		scanf("%s",s);
		FOR(j,1,m) a[i][j]=(s[j-1]=='R');
	}
	if (a[1][1]==1 || a[n][m]==1) return puts("0"),0;
	if (n==1 && m==1) return puts("1"),0;
	FORD(i,n,1){
		FORD(j,m,1){
			you[i][j]=you[i][j+1]+(a[i][j]==0);
			xia[i][j]=xia[i+1][j]+(a[i][j]==0);
		}
	}
	f[1][1][0]=1;
	f[1][1][1]=1;
	FOR(i,1,n)
		FOR(j,1,m){
			(f[i][j][0]+=g[i][j][0])%=MO;
			(f[i][j][1]+=g[i][j][1])%=MO;
			(g[i+1][j][0]+=g[i][j][0])%=MO;
			(g[i][j+1][1]+=g[i][j][1])%=MO;
			
			FOR(k,0,1){
			
				if (f[i][j][k]!=0){
					if (k==0 && you[i][j+1]>0){
						int most=you[i][j+1];
						//f[i][j+1][1]..f[i][j+most][1] + f[i][j][0]
						(g[i][j+1][1]+=f[i][j][k])%=MO;
						(g[i][j+most+1][1]-=f[i][j][k])%=MO;
						
					}
					if (k==1 && xia[i+1][j]>0){
						int most=xia[i+1][j];
						//f[i+1][j][0]..f[i+most][j][0] + f[i][j][1]
						(g[i+1][j][0]+=f[i][j][k])%=MO;
						(g[i+most+1][j][0]-=f[i][j][k])%=MO;
					}
				}
			}
	}
	ans=((f[n][m][0]+f[n][m][1])%MO+MO)%MO;
	cout<<ans<<endl;
	return 0;
}