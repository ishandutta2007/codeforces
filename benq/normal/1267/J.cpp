#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define ook order_of_key
#define fbo find_by_order

using namespace std;

template<class T> using Tree = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
	
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair

#define f first
#define s second
#define all(x) begin(x), end(x)

typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;

template<class T> bool ckmin(T& a, const T& b) {
	return a > b ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }

typedef string str;

int T,n;
int c[2000005];
vector<int> num;

bool calc(int &cnt, int a,int s) {
	int k=(a+s-1)/s;
	if (k*(s-1)<=a){
	cnt+=k;return true;}
	//cout<<"fail"<<a<<' '<<s<<endl;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	scanf("%d",&T);
	for(int qi=1;qi<=T;qi++) {
		scanf("%d",&n);
		for(int i=1;i<=n;i++)c[i]=0;
		for(int i=1;i<=n;i++) {
			int a;
			scanf("%d",&a);
			c[a]++;
		}
		num.clear();
		for(int i=1;i<=n;i++) {
			if(c[i]>0) {
				num.push_back(c[i]);
			}
		}
		sort(num.begin(),num.end());
		int m=1e9;
		for(int s=1;s-1<=num[0];s++) {
		//cout<<"s="<<s<<endl;
			int cnt=0;
			for(int i=0;i<num.size();i++) {
				if(!calc(cnt,num[i],s))
					{cnt=1e9;break;}
			}
			//cout<<"cnt="<<cnt<<endl;
			m=min(m,cnt);
		}
		printf("%d\n",m);
	}
	
}