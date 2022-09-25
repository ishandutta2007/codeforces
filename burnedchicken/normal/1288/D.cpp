#include <bits/stdc++.h>
 
#define ll long long
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

const int Mod=1e9+7;

bool comp_pii(pii a, pii b){return a>b;}
bool comp(int a, int b){return a>b;}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m,x;
	cin >> n >> m;
	int a[n][m];
	int num[m*n];
	rep(n){
		rep1(j,m){
			cin >> a[i][j];
			num[i*m+j]=a[i][j];
		}
	}
	sort(num,num+m*n,comp);
	int l=0,r=m*n-1,ans1,ans2;
	bool ok,found,b[pow2(m)];
	int subset[n];
	vector<int> vec;
	while(l<=r){
		x=(l+r)/2;
		rep(n) subset[i]=0;
		rep(n){
			rep1(j,m){
				if(a[i][j]>=num[x]) subset[i]+=pow2(j);
			}
		}
		rep(pow2(m)) b[i]=false;
		rep(n) b[subset[i]]=true;
		vec.clear();
		rep(pow2(m)) if(b[i]) vec.pb(i);
		ok=true;
		found=false;
		rep(vec.size()){
			rep2(j,i,vec.size()){
				ok=true;
				rep1(k,m) if((!(vec[i]&pow2(k)))&&(!(vec[j]&pow2(k)))) ok=false;
				if(ok){
					rep1(k,n){
						if(subset[k]==vec[i]) ans1=k;
						if(subset[k]==vec[j]) ans2=k;
					}
					found=true;
					break;
				}
			}
			if(found) break;
		}
		if(l==r) break;
		if(found) r=x;
		else l=x+1;
	}
	cout << ans1+1 << ' ' << ans2+1 << "\n";
	return 0;
}