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
const int MAXN=151,MAXM=60,moder=51123987;
int f[MAXN][MAXM][MAXM][MAXM],ans,n,next[MAXN][3],bucket[3];
char s[MAXN];
il void add(int& a,int& b){a=(a+b)%moder;}
int main(){
	cin>>n>>(s+1);
	bucket[0]=bucket[1]=bucket[2]=-1;
	per(i,n,1){
		bucket[s[i]-'a']=i;
		next[i][0]=bucket[0];next[i][1]=bucket[1];next[i][2]=bucket[2];

	}
	f[1][0][0][0]=1;
	rep(i,1,n){
		rep(a,0,min((ll)n,55LL)){
			rep(b,0,min(n-a,55LL)){
				rep(c,0,min(n-a-b,55LL)){
					//aa,bb,cc
					if(a+b+c==n && abs(a-b)<=1 && abs(a-c)<=1 && abs(b-c)<=1){
						add(ans,f[i][a][b][c]);
						continue;
					} 
					if(next[i][0]!=-1)add(f[next[i][0]][a+1][b][c],f[i][a][b][c]);
					if(next[i][1]!=-1)add(f[next[i][1]][a][b+1][c],f[i][a][b][c]);
					if(next[i][2]!=-1)add(f[next[i][2]][a][b][c+1],f[i][a][b][c]);
				}
			}
		}
	}
	cout<<ans;	
	return 0;
}