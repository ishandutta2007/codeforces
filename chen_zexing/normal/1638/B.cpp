#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        vector <int> v[2];
        for(int i=1,t;i<=n;i++) scanf("%d",&t),v[t%2].push_back(t);
        int f=1;
        for(int i=0;i<2;i++)
            if(v[i].size()){
                for(int j=1;j<v[i].size();j++)
                    if(v[i][j]<v[i][j-1])
                        f=0;
            }
        puts(f?"Yes":"No");
    }
    return 0;
}
//unordered_map