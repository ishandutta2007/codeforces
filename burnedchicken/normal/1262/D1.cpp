#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;

struct num{
	int val,pos;
};

bool comp(num x, num y){
	if(x.val!=y.val) return x.val>y.val;
	return x.pos<y.pos;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	num a[n];
	loop(n){
		cin >> a[i].val;
		a[i].pos=i;
	}
	int m;
	cin >> m;
	num b[n];
	loop(n) b[i]=a[i];
	sort(b,b+n,comp);
	vector<int> vec,vec2;
	loopi(noob,m){
		int k,p;
		cin >> k >> p;
		vec.clear();
		loop(k){
			vec.push_back(b[i].pos);
		}
		sort(vec.begin(),vec.end());
		vec2.clear();
		loop(k){
			vec2.push_back(a[vec[i]].val);
		}
		cout << vec2[p-1] << "\n";
	}
	return 0;
}