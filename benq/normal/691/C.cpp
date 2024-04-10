#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

const int MOD = 1000000007;
double PI = 4*atan(1);

int a = -1,b,c; // a is pos of period, b is 1st significant, c is last significant
bool b2;
string x;

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
    int per = -1, po = 0;
	cin >> x;

	F0R(i,x.length()) {
	    if (x[i] == '.') a = i;
	    else {
            if (x[i] != '0') {
                c = i;
                if (b2 == 0) {
                    b = i;
                    b2 = 1;
                }
            }
	    }
	}
	if (a == -1) {
        a = x.length();
        x += '.';
	}
	if (c>a) x.erase(x.begin()+c+1,x.end());
	else {
        x.erase(x.begin()+c+1,x.end());
        po = a-x.length();
        a = x.length();
        x += '.';
	}
    if (b>0) {
        if (a>b) {
            x.erase(x.begin(),x.begin()+b);
            a -= b;
        } else {
            int a1 = x.length()-a;
            x.erase(x.begin(),x.begin()+b);
            x.insert(x.begin()+1,'.');
            po -= (a1-(x.length()-1));
            a = 1;
        }
    }
	if (a>1) {
        x.erase(x.begin()+a);
        x.insert(x.begin()+1,'.');
        po += (a-1);
	}

	if (x.length() == 2) cout << x[0];
	else cout << x;
	if (po) cout << 'E' << po;
}