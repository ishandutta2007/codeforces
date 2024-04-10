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

const int N=300005,M=65;
ll mask[N],val[N],sum,ans;
int n;

int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld%lld",&val[i],&mask[i]);
		sum+=val[i];
	}
	if(sum<0)
		rep(i,1,n)val[i]*=-1;
	REP(k,62){
		ll b=1ll<<k,owo=0;
		rep(i,1,n)
			if(mask[i]==b)owo-=val[i];
		if(owo<0)ans|=b;
		rep(i,1,n)
			if(mask[i]&b){
				if(owo<0)val[i]*=-1;
				mask[i]^=b;
			}
	}
	cout<<ans<<endl;
	return 0;
}