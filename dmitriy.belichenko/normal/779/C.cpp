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

int n, k;
vector<pair<long long, long long> > v;
long long res = 0;

bool comp(pair<long long, long long> a, pair<long long, long long> b)
{
    if (a.first - a.second < b.first - b.second) return true;
    else return false;
}

int main()
{
    cin >> n >> k;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;
    for (int i = 0; i < n; i++) cin >> v[i].second;
    sort(v.begin(), v.end(), comp);
    int p = 0;
   for(p = 0; p < n; p++)
    {
        int del =v[p].first - v[p].second;
        if(p >= k && del >= 0) break;
        res += v[p].first;
        
    }
   
    
    
    for(int i = p; i < n; i++)
    {
        res += v[i].second;
    }
       cout << res;
  
}