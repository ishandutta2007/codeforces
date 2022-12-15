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
vector <int> v[505];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1,x;i<=n;i++) scanf("%d",&x),v[x].push_back(i);
        for(int i=n-3;i>=1;i--)
            for(int j=1;j<=n-2;j++){
                int a=j,b=j+i;
                if(b>n-2) continue;
                for(int k=0;k<v[a].size();k++)
                    for(int l=0;l<v[b].size();l++){
                        printf("? %d %d\n",v[b][l],v[a][k]);
                        fflush(stdout);
                        char s[5];
                        scanf("%s",s);
                        if(s[0]=='Y'){
                            printf("! %d %d\n",v[b][l],v[a][k]);
                            return 0;
                        }
                    }
            }
        for(int i=1;i<=n-2;i++)
            for(int j=0;j<v[i].size();j++)
                for(int k=j+1;k<v[i].size();k++){
                    printf("? %d %d\n",v[i][j],v[i][k]);
                    fflush(stdout);
                    char s[5];
                    scanf("%s",s);
                    if(s[0]=='Y'){
                        printf("! %d %d\n",v[i][j],v[i][k]);
                        return 0;
                    }
                }
        puts("! 0 0\n");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp