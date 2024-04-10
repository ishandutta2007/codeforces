#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound

ll a,b,n,l,t,m,L,R,M,i;

int main() {
	cin>>a>>b>>n;
	F0R(i,n) {
  		cin>>l>>t>>m;
  		if (t < a+(l-1)*b) {
  			cout << -1 << endl;
  			continue;
  		}
  		L=1;
  		R=10000000;
  		while (L<R) {
    		M=(L+R+1)/2;
    		if ((2*a+(l+M-2)*b)*(M-l+1)>t*m*2) R=M-1;
    		else L=M;
   		}
  		cout<<min(R,(t-a+b)/b)<<endl;
 	}
}