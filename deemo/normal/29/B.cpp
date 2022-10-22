/*
    He's nervous, but on the surface he looks calm and ready.. :/
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<utility>
#include<iomanip>
#include<fstream>
#include<list>
#include<sstream> 
#include<cstring>
#include<bitset>
#include<functional>

using namespace std;

typedef long long ll;
//#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define pb push_back
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)
#define PQ priority_queue;

double l , d , v , g , r;

int main(){
    setprecision(8);
    cin >> l >> d >> v >> g >> r;
    double ans = d / v;
    double t = d / v;
    while (t >= (g + r)) t -= (g + r);
    if (t >= g)  t -= g , ans += (r - t);
    ans += (l - d) / v;
    cout << ans << endl;
    return 0;
}