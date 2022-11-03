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
#include <map>

using namespace std;

int arr[100005];
int cnt[100005];
vector <int> vals;
vector <vector <int> > pos,s;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
        if (arr[i]<=100000) cnt[arr[i]]++;
    }
    for(int i=1;i<=100000;++i)
        if (cnt[i]>=i) vals.push_back(i);
    pos.resize(vals.size());
    for(int i=0;i<n;++i)
        if (arr[i]<=100000&&cnt[arr[i]]>=arr[i]) {
            pos[lower_bound(vals.begin(),vals.end(),arr[i])-vals.begin()].push_back(i);
        }
    s.resize(vals.size(),vector <int>(n,0));
    for(int i=0;i<vals.size();++i) {
        s[i][0]=arr[0]==vals[i];
        for(int j=1;j<n;++j)
            s[i][j]=s[i][j-1]+(vals[i]==arr[j]);
    }
    for(int i=0;i<q;++i) {
        int l,r,ans=0;
        scanf("%d%d",&l,&r); --l; --r;
        for(int j=0;j<vals.size();++j) {
//          int lp=lower_bound(pos[j].begin(),pos[j].end(),l)-pos[j].begin(),
//              rp=upper_bound(pos[j].begin(),pos[j].end(),r)-pos[j].begin()-1;
            int lp=s[j][r]-(l>0 ? s[j][l-1] : 0);
            if (lp==vals[j]) ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}