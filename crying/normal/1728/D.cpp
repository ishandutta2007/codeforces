#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2010;
int T,n;
char s[MAXN];
int f[MAXN][MAXN];
void solve(){
	cin>>(s+1);
	n=strlen(s+1);
	rep(i,1,n+1)f[i][i-1]=0;
	//
	rep(len,2,n)if(even(len))rep(i,1,n){
		int j=i+len-1;if(j>n)break;
		f[i][j]=-1;
		rep(a,0,1){
			int res=1;
			rep(b,0,1){
				int to=f[i+(!a)+(!b)][j-a-b];
				if(to)res=min(res,to);
				else{
					char A,B;
					if(!a){
						A=s[i];
						if(!b)B=s[i+1];
						else B=s[j];
					}else{
						A=s[j];
						if(!b)B=s[i];
						else B=s[j-1]; 
					}
					int val;
					if(A<B)val=1;
					else if(A==B)val=0;
					else val=-1;
					res=min(res,val);
				}
			}
			f[i][j]=max(f[i][j],res);
		}
	} 
	//	
	if(f[1][n]==1)cout<<"Alice\n";
	else if(f[1][n]==-1)cout<<"Bob\n";
	else cout<<"Draw\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)solve();
	
	return 0;
}