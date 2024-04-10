#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 1e5;
bool used[N][10];
set<string> ans;
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    vector<string> t;
    string a , b;
    cin >> a >> b;
    for(int i = 0; i <= a.size(); i++)
    {
        for(int j = 0; j <= b.size(); j++)
        {
            string p = a.substr(0 , i) + b.substr(0 , j);
            if(a.substr(0 , i).size() > 0 && b.substr(0 , j).size() > 0)
            if(p.size() > 0)
            t.pb(p);
        }
    }
    sort(t.begin(), t.end());
    cout << t[0] << "\n";
    return 0;
}