#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

bool ok(string & a,string & b) {
    for(int i=0;i<a.size()&&i<b.size();++i)
        if (a[i]!='0'&&b[i]!='0') return false;
    return true;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    string arr[102]; arr[n]="";
    for(int i=0;i<n;++i) {
        cin >> arr[i];
        reverse(arr[i].begin(),arr[i].end());
    }
    sort(arr,arr+n);
    vector <string> ans,add;
    int start=0;
    for(int i=0;i<n;++i)
        if (arr[i]=="0") {
            ans.push_back(arr[i]);
            ++start;
        }
    for(int i=start;i<=n;++i)
        for(int j=i;j<=n;++j)
            if (ok(arr[i],arr[j]))
                for(int t=j;t<=n;++t) {
                    if (ok(arr[j],arr[t])&&ok(arr[i],arr[t])) {
                        int nsize=(i!=n)+(j!=n)+(t!=n);
                        if (nsize>add.size()) {
                            add.clear();
                            if (i!=n) add.push_back(arr[i]);
                            if (j!=n) add.push_back(arr[j]);
                            if (t!=n) add.push_back(arr[t]);
                        }
                    }
                }
    ans.insert(ans.begin(),add.begin(),add.end());
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();++i) {
        if (i) cout << " ";
        reverse(ans[i].begin(),ans[i].end());
        cout << ans[i];
    }
    cout << endl;
    return 0;
}