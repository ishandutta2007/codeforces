#include<cstdio> 
#include<cctype>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<bitset>
using namespace std;


#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}
inline void cmax(int &a,int b){ ((a<b)&&(a=b)); }
inline void cmin(int &a,int b){ ((a>b)&&(a=b)); }


const int N=110;



int n,m,k;
int cnt[N],c;
int a[N];


int main(){
	rep(kase,1,rd()) {
		n=rd(),rd(),m=rd();
		rep(i,1,n) a[i]=rd();
		int ans=1e9;
		rep(i,1,n-m+1) {
			memset(cnt,0,sizeof cnt);
			c=0;
			rep(j,i,i+m-1) if(++cnt[a[j]]==1) c++;
			cmin(ans,c);
		}
		printf("%d\n",ans);
	}
}