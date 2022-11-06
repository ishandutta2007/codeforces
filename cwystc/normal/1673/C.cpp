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
bool p[200010];
int T,n,f[200010],top,ts,stk[200010],tmp[200010];

bool pld(int x){
	int top=0;
	while (x){
		stk[++top]=x%10;
		x=x/10;
	}
	FOR(i,1,top) if (stk[i]!=stk[top-i+1]) return 0;
	return 1;
}
void doit(){
	scanf("%d",&n);
	printf("%d\n",f[n]);
}
int main(){
    
	n=40000;
	f[0]=1;
	FOR(i,1,n){
		if (pld(i)) p[i]=1,tmp[++ts]=i;
	}
	FOR(j,1,ts){
		FOR(i,1,n) if (i>=tmp[j]) (f[i]+=f[i-tmp[j]])%=MO;
	}
	scanf("%d",&T);
	while (T--) doit();
    return 0;
}