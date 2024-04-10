#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000010

int n, m;
string a, b, s;
int arr[MAXN], brr[MAXN];
pair<long long, int> bit[MAXN];
long long ans = 0;

void upd(int id, int sgn){
    int tmp = id;
    for(; id<MAXN; id = id|(id+1)){
        bit[id].first += sgn*tmp;
        bit[id].second += sgn;
    }
}

pair<long long, int> sum(int r){
    pair<long long, int> res = {0, 0};
    for(; r >= 0; r = (r&(r+1))-1){
        res.first += bit[r].first;
        res.second += bit[r].second;
    }
    return res;
}

pair<long long, int> sum(int l, int r){
    auto a = sum(r), b = sum(l-1);
    return {a.first-b.first, a.second-b.second};
}

void calc1(){
    string tmp = s+"$"+a;
    vector<int> bruh(tmp.size());
    for(int i = 1, l = 0, r = 0; i<tmp.size(); ++i){
        if(i <= r) bruh[i] = min(r-i+1, bruh[i-l]);
        while(i+bruh[i] < tmp.size() && tmp[bruh[i]] == tmp[i+bruh[i]]) ++bruh[i];
        if(i + bruh[i] - 1 > r) l = i, r = i+bruh[i]-1;
    }
    for(int i = m+1; i<tmp.size(); i++) arr[i-m-1] = bruh[i];
    // for(int i = 0; i<tmp.size(); i++) cout << bruh[i] << endl;
}

void calc2(){
    string tmp = b+"$"+s; reverse(tmp.begin(), tmp.end());
    vector<int> bruh(tmp.size());
    for(int i = 1, l = 0, r = 0; i<tmp.size(); ++i){
        if(i <= r) bruh[i] = min(r-i+1, bruh[i-l]);
        while(i+bruh[i] < tmp.size() && tmp[bruh[i]] == tmp[i+bruh[i]]) ++bruh[i];
        if(i + bruh[i] - 1 > r) l = i, r = i+bruh[i]-1;
    }
    for(int i = m+1; i<tmp.size(); i++) brr[n-1-(i-m-1)] = bruh[i];
}


int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cin >> a >> b >> s;
    calc1();
    calc2();
    fill(bit, bit+MAXN, make_pair(0, 0));
    // for(int i = 0; i<n; i++) cout << arr[i] << " ";
    // cout << endl;
    // for(int i = 0; i<n; i++) cout << brr[i] << " ";
    // cout << endl;
    for(int i = 0, r = -1; i<n; i++){
        while(r < min(i+m-2, n-1)){
            ++r; upd(brr[r], 1);
        }
        if(i != 0) upd(brr[i-1], -1);
        int top = min(arr[i], m-1);
        auto res1 = sum(m-arr[i], m-1);
        auto res2 = sum(m, m);
        ans += (1ll*top*res1.second-1ll*m*res1.second+res1.first+res1.second)+1ll*res2.second*(top);
    }
    cout << ans << endl;
}