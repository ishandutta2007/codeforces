#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
priority_queue<int,vector<int>,greater<int> > Q;
int a[N],b[N],n,K,now;
ll ans;

int main(){
	read(n),read(now);
	rep(i,1,n)read(a[i]);
	read(K);
	rep(i,1,n)read(b[i]);
	rep(i,1,n){
		Q.push(b[i]);
		while(now<a[i]){
			if(Q.empty()){
				puts("-1");
				return 0;
			}
			now+=K;
			ans+=Q.top();
			Q.pop();
		}
		if(now<a[i]){
			puts("-1");
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}