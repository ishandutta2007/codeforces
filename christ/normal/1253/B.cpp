#include<bits/stdc++.h>
using namespace std;
#define fail return !printf ("-1\n")
typedef pair<int,int> pii;
const int MN = 2e5+1, INF = 2e9;
set<int> seen, in;
vector<int> ans;
int main() {
    int n,last=-1;
    scanf ("%d",&n);
    vector<int> a(n);
    for (auto &au : a) scanf ("%d",&au);
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (seen.count(a[i]) || in.count(a[i])) fail;
            seen.insert(a[i]);
            in.insert(a[i]);
        } else {
            if (!in.count(-a[i])) {fail;}
            in.erase(-a[i]);
            if (in.empty()) {seen.clear(); ans.push_back(i-last);last=i;}
        }
    }
    if (last != n-1) fail;
    printf ("%d\n",ans.size());
    for (int i = 0; i < ans.size(); i++) printf ("%d%c",ans[i]," \n"[i==ans.size()-1]);
    return 0;
}
//11649,6796