
#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

int main()
{
    ios_base:: sync_with_stdio(0);
    cin.tie();
    cout.tie(0);
    int n , x , y;
    cin >> n;
    cin >> x >> y;
    int d = y - x;
    int u = 0;
    for(int i=2;i<n; i++)
    {
        cin >> x;
        if(x != y + d ) u = 1;
        y = x;
    }
    if(!u) cout << y + d;
    else cout << y;
}