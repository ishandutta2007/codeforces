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
char s[200005];
int ans[200005],f[200005];
vector <int> v[3];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,t=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=0;i<=9;i++){
            v[1].clear(),v[2].clear();
            for(int j=1;j<=n;j++) f[j]=0;
            for(int j=1;j<=n;j++){
                if(s[j]>i+'0') f[j]=2,v[2].push_back(j);
                else if(s[j]<i+'0') f[j]=1,v[1].push_back(j);
            }
            //cout<<v[1].size()<<" "<<v[2].size()<<endl;
            int fl=1;
            if(v[1].size()) for(int j=0;j<v[1].size()-1;j++) if(s[v[1][j]]>s[v[1][j+1]]) fl=0;
            // cout<<"#";
            if(v[2].size()) for(int j=0;j<v[2].size()-1;j++) if(s[v[2][j]]>s[v[2][j+1]]) fl=0;
            //cout<<"#";
            int st,ed;
            st=v[1].size()?v[1][v[1].size()-1]+1:1;
            ed=v[2].size()?v[2][0]-1:n;
            //for(int j=1;j<=n;j++) cout<<f[j];puts("");
            for(int j=st;j<=n;j++) if(f[j]==0) f[j]=1;
            for(int j=1;j<=ed;j++) if(f[j]==0) f[j]=2;
            for(int j=1;j<=n;j++) if(f[j]==0) fl=0;
            if(fl){
                t=1;
                for(int j=1;j<=n;j++) printf("%d",f[j]);
                puts("");
                break;
            }
        }
        if(!t) puts("-");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp