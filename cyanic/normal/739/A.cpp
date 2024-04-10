#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int n,m,l,r,mn=N;

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(l),read(r);
		mn=min(mn,r-l+1);
	}
	printf("%d\n",mn);
	rep(i,1,n){
		printf("%d%c",i%mn," \n"[i==n]);
	}

	return 0;
}