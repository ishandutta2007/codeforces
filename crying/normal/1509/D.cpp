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
const int MAXN=6e5+10;
ll T,n;
char s[4][MAXN],ans[MAXN];
void output(int len){
	rep(i,1,len)cout<<ans[i];cout<<endl;
} 
bool solve(int i,int j,int k){
	int len=2*n;
	rep(x,1,2*n)ans[x]=s[i][x];
	int pos=1;
	rep(x,1,len){
		if(ans[x]==s[j][pos]){
			pos++;
		}
		if(pos>2*n)break;
	}
	rep(x,pos,2*n)ans[++len]=s[j][x];
	pos=1;
	rep(x,1,len){
		if(ans[x]==s[k][pos]){
			pos++;
		}
		if(pos>2*n)break;
	}
	rep(x,pos,2*n)ans[++len]=s[k][x];
	if(len<=3*n){
		output(len);return true;
	}
	printf("HERE\n");
	return false;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>s[1]+1>>s[2]+1>>s[3]+1;
		int i=1,j=1,k=1;
		while(i<=2*n && j<=2*n && k<=2*n){
			if(s[1][i]==s[2][j]){
				cout<<s[1][i];
				i++,j++;
			}else if(s[1][i]==s[3][k]){
				cout<<s[1][i];
				i++,k++;
			}else{
				cout<<s[2][j];
				j++,k++;
			}
		}
		if(i>2*n){
			if(j>k){
				rep(x,j,2*n)cout<<s[2][x];
			}else{
				rep(x,k,2*n)cout<<s[3][x];
			}
		}else if(j>2*n){
			if(i>k){
				rep(x,i,2*n)cout<<s[1][x];
			}else{
				rep(x,k,2*n)cout<<s[3][x];
			}
		}else{
			if(i>j){
				rep(x,i,2*n)cout<<s[1][x];
			}else{
				rep(x,j,2*n)cout<<s[2][x];
			}
		}
		cout<<endl;
	}

	return 0;
}