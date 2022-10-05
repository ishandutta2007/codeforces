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

const int N=1000005;
int x[N],mn[N],mx[N],n,K,ans;

void chk(int a,int b){
	if(mx[a]<mn[b])ans++;
}

int main(){
	cin>>n>>K;
	rep(i,1,n)mn[i]=1e9;
	rep(i,1,K){
		cin>>x[i];
		mn[x[i]]=min(mn[x[i]],i);
		mx[x[i]]=max(mx[x[i]],i);
	}
	rep(i,1,n-1)chk(i,i+1),chk(i+1,i);
	rep(i,1,n)chk(i,i);
	printf("%d\n",ans);
	return 0;
}