#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

ll a[100005];

int main()
{
	IO_OP;
	
	ll n, k, m, i, sum=0, tmp;
    long double mx;
    cin >> n >> k >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a+1, a+n+1);
    mx = (long double)(sum+min(m, n*k))/(long double)(n);
    for(int i=1;i<=min(n-1, m);i++) {
        sum -= a[i];
        tmp = sum + min(m-i, (n-i)*k);
        mx = max(mx, (long double)(tmp)/(long double)(n-i));
    }
    cout<<fixed<<setprecision(20)<<mx<<endl;
}