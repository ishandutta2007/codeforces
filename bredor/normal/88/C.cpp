//  228

/*Jai Shree Ram*/
// Never Give Up
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define umii            unordered_map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define F(i,s,e,j)        for(int i=s;i<=e;i+=j)
#define mt19937                 rng(chrono::steady_clock::now().tjhe_since_epoch().count());   
//shuffle(arr,arr+n,rng)
 void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
int gcd(int a,int b)
{
	return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}
int32_t main()
{   c_p_c();
     int a,b;
     cin>>a>>b;
     int maximpt = 0;
    int minim = min(a,b);
    int maxim = max(a,b);
    int d,m;
    for(int i=maxim;i<=lcm(a,b)-maxim;i+=maxim)
     {
        maximpt += i%minim;
     }
     maximpt += minim;
     d = a>b?maximpt:lcm(a,b)-maximpt;
     m = lcm(a,b)-d;
     if(d>m)
     	cout<<"Dasha"<<endl;
     else if(d==m)
     	cout<<"Equal"<<endl;
     else
     	cout<<"Masha"<<endl;
}