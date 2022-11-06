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
const int INF=1e9+10;
char c,tmp[555555],a[2010][2010];
int f[2010][2010],n,k,t[2010][2010],ts;
int main(){
	cin>>n>>k;
	FOR(i,1,n){
		scanf("%s",a[i]+1);
	}
	if (k && a[1][1]!='a'){
		a[1][1]='a';
		--k;
	}
	f[1][1]=0;
	tmp[++ts]=a[1][1];
	FOR(i,3,n+n){
		c='z'+1;
		FOR(j,max(1,i-n),min(i-1,n)){
			//j,i-j
			t[j][i-j]=INF;
			if (j>1) t[j][i-j]=min(t[j][i-j],f[j-1][i-j]);
			if (i-j>1) t[j][i-j]=min(t[j][i-j],f[j][i-j-1]);
			if (t[j][i-j]<k){
				c='a';
			}
			else if (t[j][i-j]<=k) c=min(c,a[j][i-j]);
		}
		FOR(j,max(1,i-n),min(i-1,n)){
			//j,i-j
			if (a[j][i-j]==c){
				f[j][i-j]=t[j][i-j];
				
			}
			else{
				f[j][i-j]=t[j][i-j]+1;
				if (f[j][i-j]>k) f[j][i-j]=INF;
			}
		}
		tmp[++ts]=c;
	}
	FOR(i,1,ts) putchar(tmp[i]);
	return 0;
}