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

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int m,k,n,a[101]={0},ok[102]={0};
    cin >> m >> k;
    for(int i=0;i<k;++i) {
        cin >> a[i];
        ok[a[i]]=true;
    }
    cin >> n;
    vector <string> nm;
    vector <int> mn,mx;
    string s;
    for(int i=0;i<n;++i) {
        cin >> s;
        nm.push_back(s);
        int t,b,cntz=0,now=0;
        cin >> t;
        bool u[102]={0};
        for(int j=0;j<t;j++) {
            cin >> b;
            u[b]=true;
            if (b==0) ++cntz;
            if (ok[b]) ++now;
        }
        int tmp=cntz,can=0;
        for(int j=0;j<k&&cntz;++j) {
            if (!u[a[j]]) can++,--cntz;
        }
        mx.push_back(now+can);
        cntz=tmp; can=0;
        for(int j=1;j<=m&&cntz;++j)
            if (!ok[j]&&!u[j]) --cntz;
        mn.push_back(now+cntz);
    }
    for(int i=0;i<n;++i) {
        bool ok0=true;
        for(int j=0;j<n;++j)
            if (i!=j) {
                if (mn[i]<mx[j]) ok0=false;
            }
        if (ok0) {
            puts("0");
            continue;
        }
        ok0=false;
        for(int j=0;j<n;++j)
            if (i!=j) {
                if (mx[i]<mn[j]) ok0=true;
            }
        if (ok0) {
            puts("1");
            continue;
        }
        puts("2");
    }
    return 0;
}