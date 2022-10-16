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
const int MAXN=510;
ll q,n,m,flag;
char s[MAXN],t[MAXN*2];
int check(char* a,char* b){
	int n=strlen(a),m=strlen(b);
	if(n!=m)return 0;
	rep(i,0,n-1){
		if(a[i]!=b[i])return 0;
	}
	return 1;
}
int main(){
	cin>>q;
	while(q--){
		cin>>(s+1)>>(t+1);
		n=strlen(s+1);m=strlen(t+1);
		flag=0;
		rep(i,1,n){
			rep(j,i,n){
				if(i-j+1>m)break;
				if(s[j]!=t[j-i+1])break;
				if(i-j+1==m){
					flag=1;
				}else{
					ll rest=m-(j-i+1);
					if(rest<j){
						ll tmp=1;
						rep(x,1,rest){
							if(t[m-x+1]!=s[j-rest+x-1]){
								tmp=0;break;
							}
						}
						flag|=tmp;
					}
				}
			}
		}
		if(flag){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}