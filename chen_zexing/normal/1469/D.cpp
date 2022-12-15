#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <int> v;
struct aans{
    int x,y;
};
vector <aans> ans;
int f[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int t=n;
        for(int i=1;i<=n;i++) f[i]=0;
        v.clear();
        while(t>2){
            v.push_back(t);
            f[t]=1;
            t=ceil(sqrt(t));
        }
        v.push_back(2);
        f[2]=1;
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        ans.clear();
        int cnt=0;
        for(int i=3;i<=n;i++)
            if(!f[i])
                ans.push_back(aans{i,n});
        //cout<<i<<" "<<n<<"*"<<endl;
        for(int i=0;i<v.size()-1;i++) ans.push_back(aans{v[i],v[i+1]}),ans.push_back(aans{v[i],v[i+1]});
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}