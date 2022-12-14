/* Generated by powerful Codeforces Tool
 * Author: calabash_boy_love_15 
 * Time: 2019-04-25 23:32:52
 * Personal Code Template: https://github.com/4thcalabash/ACM-Code-Library
**/
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#ifdef __LOCAL_DEBUG__
# define _debug(fmt, ...) fprintf(stderr, "\033[91m[%s %3d]: " fmt "\n\033[0m", \
  __func__,__LINE__, ##__VA_ARGS__)
#else
# define _debug(...) (void(0))
#endif
#define PB(x) push_back(x)
#define rep(i,l,r) for (int i = l,_ = r;i< _;i++)
#define REP(i,l,r) for (int i=l,_=r;i<=_;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)
#define range(x) x.begin(),x.end()
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;
const ll inf_ll = 0x3f3f3f3f3f3f3f3fLL;
/************* header ******************/


const int maxn = 100+5;
map<int,int> cnt;
int a[maxn];
int n;
int main(){
    cin>>n;
    int min_ = INT_MAX;
    int max_ = -1;
    for (int i=0;i<n;i++){
        cin>>a[i];
        min_ = min(min_,a[i]);
        max_ = max(max_,a[i]);
    }
    if (min_== max_){
        cout<<0<<endl;
        return 0;
    }
    for (int d = 1;d<=10000;d++){
        cnt.clear();
        for (int i=0;i<n;i++){
            cnt[a[i]] ++;
            cnt[a[i] - d] ++;
            cnt[a[i] + d] ++;
        }
        for (auto pr : cnt){
            if (pr.second == n){
                cout<<d<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}