#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,ll> pii;
#define fi first
#define se second
int n,m,k;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		vector<pii>a,b;
		scanf("%d%d",&n,&m);
		while(n--){
			int x;scanf("%d",&x);
			int cnt=1;
			while(x%m==0)x/=m,cnt*=m;
			if(!a.empty()&&a.back().fi==x)
				a[a.size()-1].se+=cnt;
			else a.push_back({x,cnt});
		}
		scanf("%d",&k);
		while(k--){
			int x;scanf("%d",&x);
			int cnt=1;
			while(x%m==0)x/=m,cnt*=m;
			if(!b.empty()&&b.back().fi==x)
				b[b.size()-1].se+=cnt;
			else b.push_back({x,cnt});
		}
		puts(a==b?"Yes":"No");
	}
}