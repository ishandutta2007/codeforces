#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
vector<int> l, r;
int main(){
    int n, m, li, ri;
    cin >> n >> m;
    vector<vector<int> > data;
    for (int i=0;i<n;i++){
        cin >> li >> ri;
        l.push_back(li);
        r.push_back(ri);
        vector<int> h, h1;
        h.push_back(li);
        h.push_back(0);
        h.push_back(i);
        h1.push_back(ri);
        h1.push_back(1);
        h1.push_back(i);
        data.push_back(h);
        data.push_back(h1);
    }
    vector<int> ll = l;
    sort(data.begin(), data.end());
    sort(l.begin(), l.end());
    vector<bool> lend;
    map<int, int> lin;
    for (int i=0;i<n;i++){
        lend.push_back(false);
    }
    int now = m - 1;
    int open = 0;
    int counter = 0;
    for (int i=0;i<2*n;i++){
        if (data[i][1] == 0){
            lin[data[i][2]] = counter;
            counter ++;
        }
        else{
            data[i][2] = lin[data[i][2]];
        }
    }
    int good;
    int ans = 0;
     for (int i=0;i<2*n;i++){
        if (data[i][1] == 0){
            open ++;
        }
        else{
            int num = data[i][2];
            if (num > now){
                lend[num] = true;
                if (open >= m){
                    if (abs(data[i][0] - l[num]) + 1 > ans){
                    ans = max(ans, abs(data[i][0] - l[num]) + 1);
                    good = data[i][0];
                    }
                }
                open --;
            }
            else{
                lend[num] = true;
                if (open >= m){
                    if (abs(data[i][0] - l[now]) + 1 > ans){
                    ans = max(ans, abs(data[i][0] - l[now]) + 1);
                    good = data[i][0];
                    }
                }
                open --;
                now ++;
                while (now < n && lend[now]){
                    now ++;
                }
                if (now == n){
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    int p = 0;
    if (ans > 0){
    for (int i=0;i<n;i++){
        if (ll[i] <= good - ans + 1 && r[i] >= good){
            cout << i + 1 << " ";
            p ++;
        }
        if (p >= m){
            break;
        }
    }
    }
    else{
        for (int i=0;i<m;i++){
            cout << i + 1 << " ";
        }
    }
    std::ios::sync_with_stdio(false);
    return 0;
}