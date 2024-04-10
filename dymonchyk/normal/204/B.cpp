#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#pragma comment("/:STACK:64000000",linker)

using namespace std;

map <int,int> f1,f2,f12;
vector <int> v;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d%d",&a,&b);
        f1[a]++; f2[b]++;
        if (a==b) f12[a]++;
        v.push_back(a);
        v.push_back(b);
    }
    int ans=-1,goal=(n+1)>>1;
    for(int i=0;i<v.size();++i) {
        if (goal-f1[v[i]]<=f2[v[i]]-f12[v[i]]&&(ans==-1||ans>goal-f1[v[i]]))
            ans=max(goal-f1[v[i]],0);
    }
    cout << ans << endl;
    return 0;
}