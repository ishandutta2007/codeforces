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
string s;
cin >> s;
  int a[8];
  for(int i = 0; i < 8; i++) a[i] = 0;
  int n = s.size();
  for(int i = 0; i < n; i++)
  {
      if( s[i] == 'B') a[0]++;
       if( s[i] == 'u') a[1]++;
        if( s[i] == 'l') a[2]++;
         if( s[i] == 'b') a[3]++;
          if( s[i] == 'a') a[4]++;
           if( s[i] == 's') a[5]++;
            if( s[i] == 'r') a[6]++;
  }

    int mn = 100001;
  for(int i = 0; i  < 7; i++)
  {

      if(i !=  4  && i != 1) mn = min( mn , a[i]);
     
      else mn = min( mn , a[i] / 2);
  }
  cout << mn;
}