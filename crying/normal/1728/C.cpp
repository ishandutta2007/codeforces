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
const int MAXN=2e5+10,INF=1e9;
int T,n,tmp;
int ans=0;
int calc(int x){
	int res=0;
	while(x)x/=10,res++;
	return res;
}
multiset<int>A,B;
void solve(){
	cin>>n;
	A.clear();B.clear();
	rep(i,1,n)cin>>tmp,A.insert(tmp);
	rep(i,1,n){
		cin>>tmp;
		if(A.find(tmp)!=A.end()){
			A.erase(A.find(tmp));
		}else{
			B.insert(tmp);
		}
	} 
	ans=0;
	while(A.size() || B.size()){
		int maxa=-INF,maxb=-INF;
		if(A.size())maxa=*A.rbegin();
		if(B.size())maxb=*B.rbegin();
		ans++;
		if(maxa>maxb){
			A.erase(A.find(maxa));
			int val=calc(maxa);
			if(B.find(val)!=B.end())B.erase(B.find(val));
			else A.insert(val);
		}else{
			B.erase(B.find(maxb));
			int val=calc(maxb);
			if(A.find(val)!=A.end())A.erase(A.find(val));
			else B.insert(val);
		}
	}
	
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)solve();
	
	return 0;
}