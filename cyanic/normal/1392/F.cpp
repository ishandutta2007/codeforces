#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=1e6+5;
ll a[N],res[N],sum;
int n;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		sum+=(a[i]-i)-(a[1]-1);
	}
	rep(i,1,n){
		res[i]=(a[1]-1)+(sum/n)+i;
	}
	rep(i,1,sum%n){
		res[i]++;
	}
	rep(i,1,n){
		printf("%lld ",res[i]);
	}
	return 0;
}