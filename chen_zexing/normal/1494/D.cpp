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
vector <int> v[250005];
int c[505][505],cnt,s[250005];
//
void solve(vector<int>vv,int from){
    vector<int> vvv[505];
    int tt=0;
    //cout<<vv.size()<<" "<<from<<endl;
    //if(vv.size()==0) return;
    if(vv.size()==1){
        v[from].push_back(vv[0]),s[vv[0]]=c[vv[0]][vv[0]];
        return;
    }
    int mx=0;
    for(int i=0;i<vv.size();i++)
        for(int j=i+1;j<vv.size();j++)
            mx=max(mx,c[vv[i]][vv[j]]);
    s[++cnt]=mx;
    int num=cnt,f[505],bl[505];
    v[from].push_back(cnt);
    for(int i=0;i<vv.size();i++) bl[i]=-1;
    for(int i=0;i<vv.size();i++)
    {
        for(int j=0;j<vv.size();j++) f[j]=0;
        for(int j=0;j<i;j++)
            if(c[vv[i]][vv[j]]==mx)
                f[bl[j]]=1;
        int fl=0;
        for(int j=1;j<=tt;j++)
            if(!f[j]) {
                vvv[j].push_back(vv[i]),bl[i]=j,fl=1;
                break;
            }
        if(!fl) vvv[++tt].push_back(vv[i]),bl[i]=tt;
    }
    //cout<<temp<<endl;
    //for(int i=0;i<vv.size();i++) printf("%d ",bl[i]);puts("");
    for(int i=1;i<=tt;i++) solve(vvv[i],num);
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&c[i][j]);
        vector <int> vv;
        for(int i=1;i<=n;i++) vv.push_back(i);
        cnt=n;
        solve(vv,0);
        printf("%d\n",cnt);
        for(int i=1;i<=cnt;i++) printf("%d ",s[i]);
        puts("");
        printf("%d\n",v[0][0]);
        for(int i=1;i<=cnt;i++)
            for(int j=0;j<v[i].size();j++)
                printf("%d %d\n",v[i][j],i);
    }
    return 0;
}