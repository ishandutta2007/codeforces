# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;



int n,m;
string s[2005];
int depth[2005][2005];


int main(int argc, const char * argv[]) {
 //   freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    cin>>n>>m;
    for (int i=1;i<=n;++i) {
        cin>>s[i];
        s[i]="#"+s[i];
    }
    for (int i=0;i<=n;++i)
        for (int j=0;j<=n;++j)
            depth[i][j]=-10000;
    vector<pair<int,int> > v1,v2,vv;
    string s1,s2;
    s1="";
    v1.clear();
    v1.push_back(make_pair(1,1));
    if (s[1][1]=='a' || m==0) {
        s1=s[1][1];
        depth[1][1]=m;
    } else {
        s1="a";
        depth[1][1]=m-1;
    }
    int xx,yy,zz;
    for (int i=1;i<=n+n-2;++i) {
        vv.clear();
        for (int i=0;i<v1.size();++i) {
            if (v1[i].second<n) vv.push_back(make_pair(v1[i].first,v1[i].second+1));
            if (v1[i].first<n) vv.push_back(make_pair(v1[i].first+1,v1[i].second));
        }
        sort(vv.begin(),vv.end());
        v2.clear();
        for (int i=0;i<vv.size();++i)
            if (i==0 || vv[i]!=vv[i-1]) v2.push_back(vv[i]);
        vv=v2;
            char mn='z';
        for (int i=0;i<vv.size();++i) {
            xx=vv[i].first,yy=vv[i].second;
            if (xx>1 && depth[xx-1][yy]>=0) {
                if (depth[xx-1][yy]>0) mn='a';
                else mn=min(mn,s[xx][yy]);
            }
            if (yy>1 && depth[xx][yy-1]>=0) {
                if (depth[xx][yy-1]>0) mn='a';
                else mn=min(mn,s[xx][yy]);
            }
        }
        s1+=mn;
        v2.clear();
        for (int i=0;i<vv.size();++i) {
            xx=vv[i].first,yy=vv[i].second;
            zz=0;
            if (s[xx][yy]!=mn) zz=1;
            if (xx>1 && depth[xx-1][yy]>=0) depth[xx][yy]=depth[xx-1][yy]-zz;
            if (yy>1 && depth[xx][yy-1]>=0) depth[xx][yy]=max(depth[xx][yy],depth[xx][yy-1]-zz);
            if (depth[xx][yy]>=0) v2.push_back({xx,yy});
        }
        v1=v2;
    }
    if (m==0) {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (depth[i][j]>0) assert(false);
    }
    cout<<s1<<endl;
}