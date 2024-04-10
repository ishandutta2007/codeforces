#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,d,m; cin >> n >> d >> m;
    vector<int> small;
    vector<int> large;
    for(int i = 0; i<n; i++){
        int a; cin >> a;
        if(a <= m) small.push_back(a);
        else large.push_back(a);
    }
    sort(small.begin(), small.end());
    sort(large.begin(), large.end());
    reverse(small.begin(), small.end());
    reverse(large.begin(), large.end());
    long long sumsmall[small.size()+1];
    long long sumlarge[large.size()+1];
    sumsmall[0] = 0;
    for(int i = 0; i<small.size(); i++){
        sumsmall[i+1] = sumsmall[i]+small[i];
    }
    sumlarge[0] = 0;
    for(int i = 0; i<large.size(); i++){
        sumlarge[i+1] = sumlarge[i]+large[i];
    }
    long long ans = 0;
    for(int i = small.size(); i >= 0; i--){
        int num = ceil((n-i+0.0)/(1.0+d));
        ans = max(ans, sumsmall[i]+sumlarge[min(num, (int)large.size())]);
    }
    cout << ans << endl;
}