#include <stdio.h>
#include <fstream>
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
#define ull unsigned long long
#define ll long long
#define ld long double
#define MAX 2e9
#define MIN -2e9
#define PI 3.14159265
#define fst first
#define scd second
#define mp make_pair
#define forn(i, x) for(int i = 0; i < x; i++)
#define pb push_back
ull INF = 1e9 + 7;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    for(int i = 0; i < n; i++)
    {
    
        cin >> a[i];
        mp[a[i]]++;
    }
    int id = -1;
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        if( mp[a[i]] >= mx)
        {
            mx = mp[a[i]];
         //   id = a[i];
        }
    }
    map<int,int> m;

    for(int i = 0; i < n; i++)
    {
        
        
        m[a[i]]++;
        if(m[a[i]] == mx) {id = a[i]; break;}
    }
    cout << id;
}