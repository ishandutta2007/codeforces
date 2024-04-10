//  228

//Never care About Rating,if u are a newbie.............
//Primary focus should be on learning different algorithms as much as u can...........

 
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define ll             long long int
#define int            ll
#define type           int
#define type1          int
#define type2          int
#define pb              push_back
#define mp              make_pair
#define pii             pair<type,type>
#define vi              vector<type>
#define fo(i,n)         for(type i=0;i<n;i++)
#define foo(i,n)        for(type i=1;i<=n;i++)
#define mi(x)             map<type1,type2>x
#define mii(x)          unordered_map<type1,type2>x
#define sta              stack<type>
#define q1               queue<type>
#define stt             unordered_set<type>
#define maxheap          priority_queue<type>
#define minheap            priority_queue<type,vi,greater<type> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define PI       3.14159265358979323846
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,typee)  typee *arr=new typee[n];
#define test(x)            int x; cin>>x; while(x--)
//#define mt19937             rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl                "\n"
#define sz()               size()
#define ct               continue
#define br               break
#define rr               return
#define I(x)                x.begin(),x.end()
#define G(x)             x.rbegin(),x.rend()
#define in(x)            insert(x);

void solve()
{
	int n;

	cin >> n;

	vector<pii>a(n);

	fo(i,n)
	{
		int temp;
		cin >> temp;
		a[i]={temp,i+1};
	}


	sort(I(a));

	fo(i,n)
	{
		for(int j=i+1;j<n;j++)
		{
			for(int k=j+1;k<n;k++)
			{
				if(a[k].ff==a[j].ff+a[i].ff)
				{
					cout<<a[k].ss<<" "<<a[j].ss<<" "<<a[i].ss<<endl;
					rr;
				}
			}
		}
	}
	cout<<"-1"<<endl;

	rr;
}


void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
#endif
}

int32_t main()
{
    c_p_c();

   
 // test(t)
    	solve();
    
    return 0;
}