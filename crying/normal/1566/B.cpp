#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
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
ll t,n;
string s;
void solve(){
	cin>>s;
	int cnt1=0,cnt2=0,cnt3=0;
	n=s.length();
	rep(i,0,n-1){
		if(s[i]=='0')cnt1++;
		else cnt2++;
		if(s[i]=='0'){
			if(i==0 || s[i-1]=='1'){
				cnt3++;
			}
		}
	}
	if(cnt1==n)printf("1\n");
	else if(cnt2==n)printf("0\n");
	else if(cnt3==1)printf("1\n");
	else printf("2\n");
}
int main(){
	cin>>t;
	while(t--){
		solve();
	}

	return 0;
}