#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=110;
int T,n,a[MAXN],b[MAXN],s0,s1;
int opt[MAXN][2],m;
int main(){
	cin>>T;
	while(T--){
		cin>>n;s0=s1=0;
		rep(i,1,n){
			cin>>a[i];
			s0+=a[i];
		}
		rep(i,1,n){
			cin>>b[i];
			s1+=b[i];
		}
		if(s0!=s1){
			printf("-1\n");continue;
		}
		m=0;
		rep(i,1,n-1){
			if(a[i]==b[i])continue;
			int cnt=abs(a[i]-b[i]);
			if(a[i]<b[i]){
				rep(j,i+1,n){
					if(a[j]>b[j]){
						while(cnt && a[j]>b[j]){
							a[i]++;a[j]--;
							m++;opt[m][1]=i;opt[m][0]=j;
							cnt--;
						}
					}
				}
			}else{
				rep(j,i+1,n){
					if(a[j]<b[j]){
						while(cnt && a[j]<b[j]){
							a[i]--;a[j]++;
							m++;opt[m][0]=i;opt[m][1]=j;
							cnt--;
						}
					}
				}
			}
		}
		printf("%d\n",m);
		rep(i,1,m){
			printf("%d %d\n",opt[i][0],opt[i][1]);
		}
	}

	return 0;
}
/*
4
4
1 2 3 4
3 1 2 4
2
1 3
2 1
1
0
0
5
4 3 2 1 0
0 1 2 3 4

*/