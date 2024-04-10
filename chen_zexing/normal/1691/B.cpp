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
#include <random>
using namespace std;
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,fl=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        vector <int> v,ans;
        for(int i=1;i<=n+1;i++){
            //cout<<i<<endl;
            if(i==n+1||(i>1&&a[i]!=a[i-1])){
                if(v.size()==1) fl=0;
                else{
                    for(int j=1;j<v.size();j++) ans.push_back(v[j]);
                    ans.push_back(v[0]);
                }
                v.clear(),v.push_back(i);
            }
            else v.push_back(i);
        }
        if(!fl) puts("-1");
        else for(auto u:ans) printf("%d ",u);
        puts("");
    }
    return 0;
}