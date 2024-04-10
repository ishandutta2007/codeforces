
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stack>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <bitset>
#include <string>
#define ull long long
#define lf long float
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
using namespace std;
typedef long long ll;
vector<int> cap;
vector<int> a[1105];
int p[1105];
int q[1105];
int V = 0;
int SV = 0;
int SE = 0;
int sum, Kp;

bool used[105];
vector<int> ans;
int cnt;
bool pri( int k)
{ if( k == 1) return false;
    for(int i = 2; i * i <= k; i++)
    {

        if( k % i == 0) return false;
    }
    return true;
}
int main()
{

	/*int n;
	cin >> n;
	vector<char> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= n; ++i)
		if (prime[i])
			if (i * 1ll * i <= n)
				for (int j = i*i; j <= n; j += i)
					prime[j] = false;*/
int n;
set<int> s;

cin >> n;
int a[n];
vector<int> b;


map<int,int> mp;
int mx = 0;
for(int i = 0 ; i < n; i++)
{
    cin >> a[i];
   // s.insert(a[i]);
if(pri(a[i])){ mp[a[i]]++; if(!s.count(a[i])) b.pb(a[i]) , s.insert(a[i]);  }
else
   for(int j = 2; j * j <= a[i]; j++)
    {
        map<int, int> p;
      if(a[i] % j == 0)
      {
       if(pri(j) && p[j] != -1){ mp[j]++; p[j] = -1; if(!s.count(j)) b.pb(j) , s.insert(j);  }
       if(pri(a[i] / j) && p[a[i] / j] != -1){ mp[a[i] / j]++; p[a[i] / j] = -1;  if(!s.count(a[i] / j)) b.pb(a[i] / j) , s.insert(a[i] / j);  }

      }
       mx = max(mx , a[i]);
   }
}

		 	//for(int i = 0; i <= mx ; i++)if(prime[i]) b.pb(i);
					//for(int i = 0; i < b.size(); i++) cout << b[i];
if( n == 1)
    {cout << "1";
    return 0;
    }
for(int i = 0; i < b.size(); i++)
{
    //cout << b[i] << " ";
    int ans = 0;
    //cout << mp[b[i]] << " " ;
    cnt = max( mp[b[i]] , cnt);
}
cout << max(cnt , 1);


}