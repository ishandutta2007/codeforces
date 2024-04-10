#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

int main()
{
    ll n , k;
    cin >> n >> k;
    if( (n / k) % 2 ) cout << "YES";
    else cout << "NO";
}