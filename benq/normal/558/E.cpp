#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

vi v[26];

int main() {
	int n,q,l,r,k;
	string s;
	cin>>n>>q>>s;
	F0R(i,n) v[s[i]-'a'].push_back(i);
	while(q--) {
	    cin >> l >> r >> k;
		int cnt=--l;
		r--;
		if(k) F0R(i,26) {
            int ss=lb(v[i].b(),v[i].e(),l)-v[i].b();
            int ff=ub(v[i].b(),v[i].e(),r)-v[i].b();
            FOR(j,ss,ff) v[i][j]=cnt++;
        } else for (int i=25;i>=0;--i) {
            int ss=lb(v[i].b(),v[i].e(),l)-v[i].b();
            int ff=ub(v[i].b(),v[i].e(),r)-v[i].b();
            FOR(j,ss,ff) v[i][j]=cnt++;
        }
	}
	
	F0R(i,26) F0R(j,v[i].size()) s[v[i][j]]=char('a'+i);
	cout<<s<<endl;
	return 0;
}