#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;

struct seg{int l,r,pos;};
bool operator <(const seg& seg1, const seg& seg2) {return seg1.r>seg2.r||(seg1.r==seg2.r&&seg1.l>seg2.l);}
bool comp(seg seg1, seg seg2) {return seg1.l>seg2.l||(seg1.l==seg2.l&&seg1.r>seg2.r);}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,k,x,y;
	cin >> n >> k;
	vector<seg> a(n);
	rep(n) cin >> a[i].l >> a[i].r;
	rep(n) a[i].pos=i+1;
	sort(a.begin(),a.end(),comp);
	multiset<seg> s;
	multiset<seg>::iterator it1;
	vector<int> ans;
	x=a[0].l;
	rep(n) if(a[i].l<x) x=a[i].l;
	y=a[0].r;
	rep(n) if(a[i].r>y) y=a[i].r;
	rep2(i,x,y+1){
		//cout << i << "\n";
		while(a.back().l==i){
			s.insert(a.back());
			//cout << a.back().l << ' ' << a.back().r << " in\n";
			a.pop_back();
		}
		if(s.empty()) continue;
		it1=s.end(),it1--;
		while((*it1).r<i){
			//cout << (*it1).l << ' ' << (*it1).r << " out\n";
			s.erase(it1);
			if(s.empty()) break;
			it1=s.end(),it1--;
		}
		while(s.size()>k){
			//cout << (*s.begin()).l << ' ' << (*s.begin()).r << " out2\n";
			ans.pb((*s.begin()).pos);
			s.erase(s.begin());
		}
	}
	cout << ans.size() << "\n";
	forall(ans,vector<int>) cout << *it << ' ';
	cout << "\n";
	return 0;
}