//  228

#include <bits/stdc++.h> 
using namespace std; 
#define int                 long long int
#define rep(i,k,n)          for(int i=k;i<n;i++)
#define pb                  push_back  
#define mkp                 make_pair
#define fi                  first
#define se                  second
#define vi                  vector <int>
#define endl				"\n"
#define all(x)              x.begin(), x.end()
#define clr(x)              memset(x, 0, sizeof(x))
#define sortall(x)          sort(all(x))
#define fill(a,b)           memset(a, b, sizeof(a))
#define deb(x)              cout << #x << "=" << x << endl
#define deb2(x, y)          cout << #x << "=" << x << "," << #y << "=" << y << endl
#define fast_io             ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v)             rep(i,0,v.size()) cout<<v[i]<<" "; cout<<endl;

const int mod = 1000000007;

int32_t main()
{
	fast_io;
	
	int tc = 1;
	//cin>>tc;
	while(tc--)
	{
		int n;
		cin>>n;
		int s = 1;
		int e = n;
		rep(i,0,n){
			if(i%2 == 0){
				cout<<s<<" ";
				s++;
			}else{
				cout<<e<<" ";
				e--;
			}
		}
	}

	return 0;
}