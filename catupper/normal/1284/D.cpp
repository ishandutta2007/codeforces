#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

Int n;
Int a[110000];
Int b[110000];
Int c[110000];
Int d[110000];

void add(vector<Int> &bit, Int ind, Int val){
    ind++;
    while(ind < bit.size()){
        bit[ind] += val;
        ind += ind & -ind;
    }
}

Int sum(vector<Int> &bit, Int ind){
    ind++;
    Int ans = 0;
    while(ind){
        ans += bit[ind];
        ind -= ind & -ind;
    }
    return ans;
}

bool check(Int *a, Int *b, Int *c, Int *d){
    vector<Int> ad[4*n+10];
    vector<Int> ch[4*n+10];
    vector<Int> bit(4*n+10, 0);
    set<Int> marker = {LINF};
    for(Int i = 0;i < n;i++){
        ad[b[i]].push_back(i);
        ch[a[i]].push_back(i);
    }

    for(Int i = 0;i < 4*n;i++){
        
        for(Int ind: ch[i]){
//            cout << d[ind] << " " << c[ind] << endl;
//            cout << sum(bit, d[ind])<< " " <<  sum(bit, c[ind]-1) << endl;
            if(sum(bit, d[ind]) != 0 ||  sum(bit, c[ind]) != 0 || *marker.lower_bound(c[ind]) <= d[ind])return false;
        }
        
        for(Int ind: ad[i]){
            marker.insert(c[ind]);
            marker.insert(d[ind]);
            add(bit, c[ind], 1);
            add(bit, d[ind] + 1, -1);
        }
    }
    return true;
}

int main(){
    vector<Int> nums = {-LINF, LINF};
    cin >> n;
    for(Int i = 0;i < n;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        nums.push_back(a[i]);
        nums.push_back(b[i]);
        nums.push_back(c[i]);
        nums.push_back(d[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    for(Int i = 0;i < n;i++){
        a[i] = lower_bound(nums.begin(), nums.end(), a[i]) - nums.begin();
        b[i] = lower_bound(nums.begin(), nums.end(), b[i]) - nums.begin();
        c[i] = lower_bound(nums.begin(), nums.end(), c[i]) - nums.begin();
        d[i] = lower_bound(nums.begin(), nums.end(), d[i]) - nums.begin();
    }

    if(check(a,b,c,d) && check(c,d,a,b))cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}