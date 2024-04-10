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

const int N=200005;
struct qry{
	ll x,id;
}q[N];
ll d[N],s[N],ans[N];
ll p,bas,l,r,rem;
int n,Q;

bool cmp(qry a,qry b){
	return a.x<b.x;
}

int main(){
	cin>>n;
	rep(i,1,n)cin>>s[i];
	sort(s+1,s+n+1);
	rep(i,1,n-1)d[i]=s[i+1]-s[i];
	cin>>Q;
	rep(i,1,Q){
		cin>>l>>r;
		q[i]=(qry){r-l+1,i};
	}
	sort(d+1,d+n);
	sort(q+1,q+Q+1,cmp);
	d[n]=2e18;
	int cur=1;rem=n;
	rep(i,1,n){
		while(cur<=Q&&q[cur].x<=d[i]){
			ans[q[cur].id]=bas+rem*q[cur].x;
			//cout<<rem<<"  "<<bas<<endl;
			cur++;
		}
		rem--,bas+=d[i];
	}
	rep(i,1,Q)printf("%lld ",ans[i]);
	return 0;
}