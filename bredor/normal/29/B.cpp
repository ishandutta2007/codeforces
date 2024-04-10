//  228

#include "bits/stdc++.h"
using namespace std;
 
#define              ll              long long
 
#define       forn(i,n)              for(int i=0;i<n;i++)
#define          all(v)              v.begin(), v.end()
#define         rall(v)              v.rbegin(),v.rend()
 
#define            pb                push_back
#define          sz(a)               (int)a.size()
#define         fastio               ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
#define GR(a,n,m) vector<vector<int>> a(n, vector<int>(m));
#define fi first
#define se second
#define int long long

template<typename T>istream& operator>>(istream&I,vector<T>&v){for(auto&i:v)I>>i;return I;}
template<typename T>ostream& operator<<(ostream&O,vector<T>&v){for(auto&i:v)O<<i<<' ';return O;}
template<typename T>istream& operator>>(istream&I,vector<vector<T>>&v){for(auto&i:v)for(auto&x:i)I>>x;return I;}
template<typename T>ostream& operator<<(ostream&O,vector<vector<T>>&v){for(auto&i:v){for(auto&x:i)O<<x<<' ';O<<'\n';}return O;}
template<typename T,typename U>istream& operator>>(istream&I,pair<T,U>&p){I>>p.first>>p.second;return I;}
template<typename T,typename U>ostream& operator<<(ostream&O,pair<T,U>&p){O<<p.first<<' '<<p.second;return O;}

void solve()
{
	int l,d,v,g,r;
	cin >> l >> d >> v >> g >> r;
	double t1 = (double)d / (double)v;

	int c = 0;
	int t=0;
	double rem = t1;
	bool G = true, R = false;
	while(rem>0)
	{
		if(G){
			if(rem>=g)rem-=g;
			else break;
		}
		if(R){
			if(rem>=r)rem-=r;
			else break;
		}
		swap(G,R);
	}

	if(R){
		for(int i = 0;i <= 1e6;i++){
			if(i*(r+g)>=t1){
				t1 = i *(r+g);
				break;
			}
		}
	}
	cout << fixed << setprecision(12) << t1+(double)(l-d)/v;
}
 
int32_t main()
{
	fastio;
    int t = 1;
   	//cin >> t;
    while(t--)
    {
        solve(); 
    }
}