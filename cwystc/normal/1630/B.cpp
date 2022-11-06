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
bool u[500010];
int T,n,k,cnt[500010],ans,X,Y,a[500100];

void doit(){
	scanf("%d%d",&n,&k);
	FOR(i,0,n) cnt[i]=0;
	FOR(i,1,n) scanf("%d",&a[i]),++cnt[a[i]];
	FOR(i,1,n) cnt[i]+=cnt[i-1];
	int y=0;
	int nd=(n+k+1)/2;
	ans=n+1;
	FOR(x,1,n){
		y=max(y,x);
		while (y<n && cnt[y]-cnt[x-1]<nd) ++y;
		if (cnt[y]-cnt[x-1]>=nd){
			if (y-x<ans){
				ans=y-x;
				Y=y;
				X=x;
			}
		}
	}
	printf("%d %d\n",X,Y);
	int now=0;
	int you=0;
	int las=0;
	FOR(i,1,n){
		if (a[i]>=X && a[i]<=Y) ++now;
		else --now;
		if (now>=1){
			++you;
			if (you==k){
				printf("%d %d\n",las+1,n);
				break;
			}
			else{
				printf("%d %d\n",las+1,i);
				las=i;
			}
			now=0;
		}
	}
	
}
int main(){
    
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}