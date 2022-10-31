#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005

unordered_map<bitset<MAXN>,int> mp;
bitset<MAXN> arr[30];
vector<pair<bitset<MAXN>, int>> v;
int n, s, d;
int a, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s >> d;
    b = s/3;
    a = s-b;
    for(int i = 0; i<s; i++){
        int c; cin >> c;
        for(int j = 0; j<c; j++){
            int x; cin >> x; --x;
            arr[i].set(x);
        }
    }
    int len1 = (1<<a);
    for(int i = 0; i<len1; i++){
        bitset<MAXN> bb;
        for(int j = 0; j<a; j++){
            if(i&(1<<j)) bb ^= arr[j];
        }
        if(!mp.count(bb)) mp[bb] = __builtin_popcount(i);
        else mp[bb] = min(mp[bb],__builtin_popcount(i));
    }
    int len2 = (1<<b);
    for(int i = 0; i<len2; i++){
        v.push_back({bitset<MAXN>(), 0});
        for(int j = 0; j<b; j++){
            if(i&(1<<j)){
                ++v.back().second; v.back().first^=arr[j+a];
            }
        }
    }
    while(d--){
        bitset<MAXN> day;
        int c; cin >> c;
        for(int i = 0; i<c; i++){
            int x; cin >> x; --x; day.set(x);
        }
        int ans = 31;
        for(auto j : v){
            day ^= j.first;
            if(mp.count(day)) ans = min(ans, j.second+mp[day]);
            day ^= j.first;
        }
        if(ans == 31) cout << -1 << endl;
        else cout << ans << endl;
    }
}