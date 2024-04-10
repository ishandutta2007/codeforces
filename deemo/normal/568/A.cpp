/*
    God save us everyone 
    will we burn inside the fires of a thousand suns?
    for the sins of our hands 
    the sins of our tongues
    the sins of our fathers
    the sins of our young..
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

int p , q;
const int max_n = 2e6;
bool pr[max_n];
int par_pr[max_n] , par_pal[max_n];

bool pal(int x){
    int t = 0 , temp = x;
    while (temp != 0){
	 t = t * 10 + (temp % 10);
	 temp /= 10;
    }
    return  t == x;
}

bool ok(int a , int b){
    a *= q;
    b *= p;
    return  b >= a;
}

int main(){
    cin >> p >> q;
    pr[1] = 1;
    for (int i = 2 ; i < max_n ; i++){
	 if (pr[i])  continue;
	 for (int j = i + i ; j < max_n ; j += i)
	     pr[j] = 1;
    }
    int cnt1 = 0 , cnt2 = 0 , ans = 1;
    for (int i = 1 ; i < max_n ; i++){
	 if (pal(i)) cnt1++;
	 if (!pr[i]) cnt2++;
	 if (ok(cnt2 , cnt1))    ans = i;
    }
    cout << ans << endl;
    return 0;
}