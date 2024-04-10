#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; int d[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
	    int n,k,l; scanf("%d%d%d",&n,&k,&l);
		rep(i,1,n) scanf("%d",&d[i]); 
		d[0]=d[n+1]=-2e9; 
		bool f=false;
		for (int i=0,j=-1;i<=n;++i){
			if (d[i+1]+k<=l){ j=-1; continue; }
			if (j<k){
				int h=l-d[i+1]; 
				if (h<0){ f=true; break; }
				j=max(j+1,k-h);
			}
			else{
				if (d[i+1]+(j+1-k)>l){ f=true; break; }
				j=(j+1)%(2*k);
			}
		}
		puts(f?"No":"Yes"); 
	}
	return 0;
}