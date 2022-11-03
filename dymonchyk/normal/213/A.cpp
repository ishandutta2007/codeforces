#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>

using namespace std;

int tm(int a,int b) {
    if (a<b) return b-a;
    return 3-(a-b);
}

vector < vector <int> > g;
int n,w[202]={0};

int solve(int s) {
    bool ok[202]={0};
    int left=n,ret=0;
    while(left) {
        bool done=true;
        while(done) {
            done=false;
            for(int i=0;i<n;++i)
                if (w[i]==s&&!ok[i]) {
                    bool can=true;
                    for(int j=0;j<g[i].size();++j)
                        if (!ok[g[i][j]]) {
                            can=false;
                            break;
                        }
                    if (can) ok[i]=true,ret++,--left,done=true;
                }
        }
        if (left) ret++; s=(s+1)%3;
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k,a;
    cin >> n;
    for(int i=0;i<n;++i) {
        cin >> w[i];
        w[i]--;
    }
    g.resize(n);
    for(int i=0;i<n;++i) {
        cin >> k;
        for(int j=0;j<k;++j) {
            cin >> a;
            g[i].push_back(a-1);
        }
    }
    cout << min(solve(0),min(solve(1),solve(2))) << endl;
    return 0;
}