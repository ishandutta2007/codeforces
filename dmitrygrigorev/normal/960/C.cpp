#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    //freopen("input.txt", "r", stdin);
    int x, d;
    cin >> x >> d;
    int diff = 1e10;
    vector<int> val;
    for (int i=1; i < 60; i++){
        val.push_back((1LL<<i)-1);
    }
    vector<int> ans;
    int st = 1;
    while (x > 0){
        for (int i=0; i < val.size(); i++)  {
            if (val[i] > x){
                x -= val[i-1];
                int num = i;
                for (int j=0; j < num; j++) ans.push_back(st);
                st += diff;
                break;
            }
        }
    }
    cout << ans.size() << endl;
    for (int i=0; i < ans.size(); i++) cout << ans[i] << " ";
    return 0;
}