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
int n,k,f[2000100],a[2000010],two[2000010],h;

int atlst(int n,int k){
	k=max(k,0);
	if (k>n) return 0;
	if (n==0) return 1;
	
	if (k==0) return 0;
	//C(n-1,k-1)%2
	if (two[n-1]-two[k-1]-two[n-k]>0) return 0;
	else return 1;
}
int wy(int l,int r){
	if (l!=1 && r!=n){
		return atlst(n-r+l-3,k-2);
	}
	else if (l==1 && r!=n){
		return atlst(n-r-1,k-1);
	}
	else if (l!=1 && r==n){
		return atlst(l-2,k-1);
	}
	else return atlst(0,k);
}
int main(){
	two[0]=0;
	FOR(i,1,2000000) two[i]=(i/2)+two[i/2];
	scanf("%d%d",&n,&k);
	FOR(i,1,n) scanf("%d",&a[i]);
	FOR(i,1,n){
		f[a[i]]^=wy(i,i);
		LL t=a[i];
		FOR(j,i+1,n){
			if (a[j]>20) break;
			t=t*(1<<a[j]);
			if (t>(1<<20)) break;
			f[t]^=wy(i,j);
		}
	}
	h=-1;
	FORD(i,(1<<20)-1,0) if (f[i]!=0){
		h=i;
		break;
	}
	if (h==-1) return puts("0"),0;
	FORD(i,h,0) putchar(f[i]+'0');
	puts("");
    return 0;
}