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
const int MAXM=510;
int n,m,w[MAXM],idx[MAXM];
ll sum,ans;
bool cmp(int x,int y){
	return w[x]<w[y];
}
int main(){
	cin>>n>>m;
	string s(m,'0');
	rep(i,1,m){
		s[i-1]='1';
		cout<<"? "<<s<<endl;
		cin>>w[i];
		s[i-1]='0';
		idx[i]=i;
	}
	sort(idx+1,idx+1+m,cmp);
	ans+=w[idx[1]];
	rep(i,0,m-1)s[i]='1';
	cout<<"? "<<s<<endl;
	cin>>sum;
	per(i,m,2){
		s[idx[i]-1]='0';
		ll tmp;
		cout<<"? "<<s<<endl;
		cin>>tmp;
		if(sum-tmp==w[idx[i]]){
			s[idx[i]-1]='1';
			ans+=w[idx[i]];
		}else sum=tmp;
	}
	cout<<"! "<<ans<<endl;
	return 0;
}