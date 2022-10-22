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

using namespace std;

typedef long long ll;
#define size(x) ((int)(x).size())
#define error(x) cerr << #x << " = " << x << endl
#define push_back pb
#define setprecision(x) cout << fixed << setprecision((x))
#define read_fast ios_base::sync_with_stdio(false) , cin.tie(0)

int a[10];
ll ans;

int main(){
    bool flag = 0;
    for (int i = 0 ; i < 6 ; i++)
        cin >> a[i];
    int t = ans = 1[a] * 2 + 1 , i;
    for (i = 2; i <= a[0] || i <= a[2] ; i++){
        if (i <= a[0] && i <= a[2]) t += 2;
        else if (!flag){
            flag = 1;
            t++;
        }
        ans += t;
     }
    if (a[0] != a[2])   t--;
    for (i = 1 ; i <= a[5] && i <= a[3] ; i++){
        ans += t;
        t -= 2;
    }
    cout << ans << endl;
    return 0;
}