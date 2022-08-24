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
int n, ai, bi;
vector<int> li, ri;
vector<int> data;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n;
    set<int> myset;
    bool flag = false;
    for (int i=0;i<n-1;i++){
        cin >> ai >> bi;
        li.push_back(ai);
        ri.push_back(bi);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    for (int i=0;i<n-1;i++){
        int c1 = data[li[i] - 1];
        int c2 = data[ri[i] - 1];
        if (c1 == c2){
            continue;
        }
        else{
            if (!flag){
                myset.insert(li[i]);
                myset.insert(ri[i]);
                flag = true;
            }
            else{
                if (myset.count(li[i])){
                    myset.clear();
                    myset.insert(li[i]);
                    continue;
                }
                if (myset.count(ri[i])){
                    myset.clear();
                    myset.insert(ri[i]);
                    continue;
                }
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    if (!flag){
        cout << 1 << endl;
        return 0;
    }
    for (int i=1;i<=n;i++){
        if (myset.count(i)){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}