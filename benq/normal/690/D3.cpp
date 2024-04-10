#include <fstream>
#include<iostream>
#include<vector>
#include<deque>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

const int MOD = 1000003;

deque<ll> nums;
ll C,W,H, po[105]; 

int main() {
    ios_base::sync_with_stdio(0);
    cin >> C >> W >> H;
    po[1] = H;
    FOR(i,2,105) po[i] = po[i-1]*H % MOD;
    nums.pb(1); nums.pb(1);
    FOR(i,1,C+1) {
        ll rec = nums.front()*(H+1) % MOD;
        if (i>W) rec = (rec-(po[W+1]*nums.back() % MOD)) % MOD;
        if (rec<0) rec += MOD;
        nums.push_front(rec);
        if (nums.size() > (W+2)) nums.pop_back();
    }
    if (nums[0]<0) nums[0] += MOD;
    cout << nums[0];
}