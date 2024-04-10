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

const int N=600005;
pii a[N],x[N],y[N];
map<pii,int> Id;
vi ans1,ans2;
int n,X,Y;

inline int cmp(pii a,pii b){
	return a.se>b.se;
}

vi solve(pii a[],int m){
	sort(a+1,a+m+1,cmp);
	vi ans;
	rep(i,1,m)
		ans.pb(Id[a[i]]);
	return ans;
}

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i].fi,&a[i].se);
		if(a[i].fi<a[i].se)x[++X]=a[i],Id[x[X]]=i;
		else y[++Y]=mp(a[i].se,a[i].fi),Id[y[Y]]=i;
	}
	ans1=solve(x,X);
	ans2=solve(y,Y);
	if(ans1.size()>ans2.size()){
		cout<<ans1.size()<<endl;
		for(auto x:ans1)printf("%d ",x);
	}
	else{
		reverse(ans2.begin(),ans2.end());
		cout<<ans2.size()<<endl;
		for(auto x:ans2)printf("%d ",x);
	}
	return 0;
}