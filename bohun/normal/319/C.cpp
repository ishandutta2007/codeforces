#include <bits/stdc++.h>
#define pb push_back
#define ld long double
#define fi first
#define se second
#define ll long long
#define ss(x) (int) x.size()
#define mp make_pair
using namespace std;
const int nax = 200005;
const ll inf = 1e18, z = 0;

const int pod = (1 << 18);
vector <ll> val;
pair<ll, ll> t[2 * pod]; // lepiej tu, bo pami wysadza w strukcie // min
pair<ll, ll> d[2 * pod]; // max

struct Lichaomin{
    void init()
    {
        for(int i = 1; 2 * pod > i; ++i)
            t[i] = {0, inf};
    }
    ll fun(pair<ll, ll> para, ll p)
    {
        return para.fi * p + para.se;
    }
    void Add(pair<ll, ll> nowa, int node = 1, int lewo = 0, int prawo = pod - 1)
    {
        ll pun = val[(lewo + prawo + 1) / 2];
        bool ok1 = (fun(t[node], lewo) > fun(nowa, lewo));
        bool ok2 = (fun(t[node], pun) > fun(nowa, pun));
        int mid = (lewo + prawo) / 2;
        if(ok2)
            swap(nowa, t[node]);
        if(lewo == prawo)
            return;
        if(ok1 != ok2)
            Add(nowa, 2 * node, lewo, mid);
        else
            Add(nowa, 2 * node + 1, mid + 1, prawo);
    }
    ll Mini(ll pun, int node = 1, int lewo = 0, int prawo = pod - 1)
    {
        ll wynik = fun(t[node], pun);
        int mid = (lewo + prawo) / 2;
        if(lewo == prawo)
            return wynik;
        if(pun <= val[mid])
            return min(wynik, Mini(pun, 2 * node, lewo, mid));
        else
            return min(wynik, Mini(pun, 2 * node + 1, mid + 1, prawo));
    }
};
struct Lichaomax{
    void init()
    {
        for(int i = 1; 2 * pod > i; ++i)
            d[i] = {0, -inf};
    }
    ll fun(pair<ll, ll> para, ll p)
    {
        return para.fi * p + para.se;
    }
    void Add(int node, int lewo, int prawo, pair<ll, ll> nowa)
    {
        int pun = (lewo + prawo + 1) / 2;
        bool ok1 = (fun(d[node], lewo) < fun(nowa, lewo));
        bool ok2 = (fun(d[node], pun) < fun(nowa, pun));
        int mid = (lewo + prawo) / 2;
        if(ok2)
            swap(nowa, d[node]);
        if(lewo == prawo)
            return;
        if(ok1 != ok2)
            Add(2 * node, lewo, mid, nowa);
        else
            Add(2 * node + 1, mid + 1, prawo, nowa);
    }
    ll Maxi(int node, int lewo, int prawo, ll pun)
    {
        ll wynik = fun(d[node], pun);
        int mid = (lewo + prawo) / 2;
        if(lewo == prawo)
            return wynik;
        if(pun <= mid)
            return max(wynik, Maxi(2 * node, lewo, mid, pun));
        else
            return max(wynik, Maxi(2 * node + 1, mid + 1, prawo, pun));
    }
};

Lichaomin ja;
int n, a[nax], b[nax];
ll dp[nax];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ja.init();
	cin >> n;
	for(int i = 1; n >= i; ++i)
		cin >> a[i], val.pb(a[i]);
	for(int i = 1; n >= i; ++i)
		cin >> b[i], val.pb(b[i]);
	sort(val.begin(), val.end());
	int j = 1;
	while(ss(val) < pod)
		val.pb(1000000000 + j), ++j;
	ja.Add({b[1], 0});
	for(int i = 2; n >= i; ++i)
	{
		dp[i] = ja.Mini(a[i]);
		ja.Add({b[i], dp[i]});
	}
	cout << dp[n];
	
		
	
	
	
	return 0;
}