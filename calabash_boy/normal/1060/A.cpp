#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/


int cnt[100];
int main(){
    untie;
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ans = s.size()/11;
    for (int i=0;i<s.size();i++){
        cnt[s[i] - '0']++;
    }
    ans = min(ans,cnt[8]);
    cout<<ans<<endl;
    return 0;
}