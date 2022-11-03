#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

vector < vector <int> > ans;

void solve(int l,int r,int lev = 0) {
    if (l==r) return;
    int m=(l+r)>>1;
    for(int i=l;i<=m;++i)
        ans[lev].push_back(i);
    solve(l,m,lev+1); solve(m+1,r,lev+1);
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    ans.resize(n);
    solve(1,n);
    for(int i=0;i<ans.size();++i)
        if (ans[i].size()==0) {
            printf("%d\n",i);
            for(int j=0;j<i;++j) {
                printf("%d",ans[j].size());
                for(int t=0;t<ans[j].size();++t)
                    printf(" %d",ans[j][t]);
                printf("\n");
            }
            break;
        }
    return 0;
}