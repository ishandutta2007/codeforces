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
long long fact(int counter){
    long long cc = 1000000007;
    long long res = 1;
    while (counter > 1){
        res = (res * counter) % cc;
        counter -= 1;
    }
    return res;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    bool used[m];
    vector<pair<int, int> > init[m];
    for (int i=0;i<m;i++){
        used[i] = false;
        vector<pair<int, int> > help;
        init[i] = help;
    }
    for (int i=0;i<n;i++){
        int k;
        cin >> k;
        int ai;
        vector<int> spisok;
        map<int, int> mymap;
        for (int j=0;j<k;j++){
            cin >> ai;
            ai = ai - 1;
            used[ai] = true;
            if (!mymap.count(ai)){
                spisok.push_back(ai);
                mymap[ai] = 1;
            }
            else{
                mymap[ai] ++;
            }
        }
        for (int j=0;j<spisok.size();j++){
            int counter = mymap[spisok[j]];
            pair<int, int> a;
            a.first = counter;
            a.second = i;
            init[spisok[j]].push_back(a);
        }
    }
    long long nole = 0;
    long long cc = 1000000007;
    vector<vector<pair<int, int> > > res;
    for (int i=0;i<m;i++){
        if (!used[i]){
            nole ++;
        }
        else{
            res.push_back(init[i]);
        }
    }
    long long ans = 1;
    if (nole > 1){
        ans = fact(nole) % cc;
    }
    sort(res.begin(), res.end());
    long long counter = 1;
    for (int i=1;i<res.size();i++){
        if (res[i - 1] == res[i]){
            counter ++;
        }
        else{
            if (counter > 1){
                ans = (ans * fact(counter)) % cc;
                counter = 1;
            }
        }
    }
    if (counter > 1){
        ans = (ans * fact(counter)) % cc;
    }
    cout << ans << endl;
    return 0;
}