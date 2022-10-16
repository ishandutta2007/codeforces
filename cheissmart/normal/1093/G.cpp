#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
const int N = 2e5+87;
struct seg
{
	int ma[32];
	seg(){}
	seg(int a[5])
	{
		for (int s = 0; s < 32; ++s) {
			ma[s] = 0;
			for (int i = 0; i < 5; ++i)
				ma[s] += (s>>i&1) ? a[i] : -a[i];
		}
	}
	seg operator + (const seg & rhs) const
	{
		seg ret;
		for(int i=0;i<32;i++) {
			ret.ma[i] = max(ma[i], rhs.ma[i]);
		} 
		return ret;
	}
}t[N*4];
int a[200005][5];
int n, k;
void bld(int o=1,int l=1,int r=n+1)
{
    if (r-l==1) {
        t[o] = seg(a[l]);
        return;
    }
    int m = l + (r-l)/2;
    bld(o+o,l,m);
    bld(o+o+1,m,r);
    t[o] = t[o<<1]+t[o<<1|1];
}
void upd(int i,int o=1,int l=1,int r=n+1)
{
    if (r-l==1) {
        t[o] = seg(a[l]);
        return;
    }
    int m = l + (r-l)/2;
    if (i < m)
        upd(i,o<<1,l,m);
    else
        upd(i,o<<1|1,m,r);
    t[o] = t[o<<1]+t[o<<1|1];
}
seg qry(int i,int j,int o=1,int l=1,int r=n+1)
{
    if (i <= l && r <= j)
        return t[o];
    int m = (l + r) / 2;
    if (j <= m)
        return qry(i,j,o<<1,l,m);
    if (i >= m)
        return qry(i,j,o<<1|1,m,r);
    return qry(i,j,o<<1,l,m) + qry(i,j,o<<1|1,m,r);
}

int main()
{
	IO_OP;
	
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			cin >> a[i][j];
	bld();
	int q;
	cin >> q;
	while(q--) {
		int op;
		cin >> op;
		if(op == 1) {
			int i;
			cin >> i;
			for(int j=0;j<k;j++)
				cin >> a[i][j];
			upd(i);
		} else {
			int l, r;
			cin >> l >> r;
			auto ret = qry(l, r+1);
			int ans = 0;
			for(int i=0;i<32;i++)
				ans = max(ans, ret.ma[i]+ret.ma[31^i]);
			cout << ans << endl;
		}
	}
}