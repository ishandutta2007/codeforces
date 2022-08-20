/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n,start,x;
// pii cur[6] = {{0,0},{97,-1},{58,5},{16,2},{81,1},{79,4}};
map<int,pii> info; // index, number, next
vi todo;

pii query(int x) {
    cout << "? " << x << endl;
    int val, nex; cin >> val >> nex;
    return {val,nex};
   // return cur[x]; 
}

int main() {
    srand(time(0));
	cin >> n >> start >> x;
	
	FOR(i,1,n+1) if (i != start) todo.pb(i);
	random_shuffle(todo.begin(),todo.end());
	todo.pb(start);
	reverse(todo.begin(),todo.end());
	
	F0R(i,min(1000,(int)todo.size())) info[todo[i]] = query(todo[i]);
	
	pii bes = {-1,-1};
	for (auto a: info) if (a.s.f < x) bes = max(bes,a.s);
	
	if (bes == mp(-1,-1)) {
	    cout << "! " << info[start].f << endl;
	} else {
	    int ind = bes.s;
	    while (ind != -1) {
	        pii a = query(ind);
	        if (a.f >= x) {
	            cout << "! " << a.f << endl;
	            return 0;
	        }
	        ind = a.s;
	    }
	    cout << "! -1" << endl;
	}
}

// read!
// ll vs. int!