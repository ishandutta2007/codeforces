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

const int N=3000005;
int c[N],n,d,ans;

int main(){
	cin>>n;
	rep(i,1,n){
		cin>>c[i];
		if(!d&&c[i]!=c[1])d=i;
		if(c[i]==c[1])ans=max(ans,i-d);
		else ans=max(ans,i-1);
	}
	cout<<ans<<endl;

	return 0;
}