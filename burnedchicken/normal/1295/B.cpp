#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const ll Mod=1000000007,Mod2=998244353;
int t,n,x,num,a[200005],Max,Min,ans;
string str;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> x >> str;
		num=0;
		rep(2*n+1){
			a[i]=0;
		}
		Max=Min=0;
		rep(n){
			if(str[i]=='0'){
				num++;
				a[n+num]++;
				Max=max(Max,num);
			}
			else{
				num--;
				a[n+num]++;
				Min=min(Min,num);
			}
		}
		if(num==0){
			if(x>=Min&&x<=Max) cout << "-1\n";
			else cout << "0\n";
			continue;
		}
		ans=0;
		if(!x) ans++;
		rep(2*n+1){
			if((x-(i-n))%num==0&&((x-(i-n)))/num>=0) ans+=a[i];
		}
		cout << ans << '\n';
	}
	return 0;
}