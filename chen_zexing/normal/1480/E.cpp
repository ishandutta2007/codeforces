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
struct edge{
    int ed,w;
};
vector <edge> v[40];
vector <int> nd;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int l,r;
        cin>>l>>r;
        if(r-l+1>(1<<30)){
            puts("NO");
            return 0;
        }
        int t=r-l+1,n=2,temp=1;
        while(temp<t) temp*=2,n++;
        puts("YES");
        for(int i=2;i<n;i++){
            int now=1;
            for(int j=2;j<i;j++) v[j].push_back(edge{i,now}),now*=2;
            v[1].push_back(edge{i,1});
        }
        t--;
        int now=(1<<(n-1));
        while(now){
            if(now<=t) t-=now,nd.push_back(now);
            now>>=1;
        }
        int tot=1;
        for(int i=nd.size()-1;i>=0;i--){
            temp=nd[i];
            int f=1;
            while(temp) temp>>=1,f++;
            //cout<<f<<" "<<nd[i]<<endl;
            //if(f==1) v[f].push_back(edge{n,1});
            v[f].push_back(edge{n,tot});
            tot+=nd[i];
        }
        v[1].push_back(edge{n,1});
        int cnt=0;
        for(int i=1;i<n;i++)
            for(int j=0;j<v[i].size();j++){
                cnt++;
                if(v[i][j].ed==n) v[i][j].w+=l-1;
            }
        printf("%d %d\n",n,cnt);
        for(int i=1;i<n;i++)
            for(int j=0;j<v[i].size();j++)
                printf("%d %d %d\n",i,v[i][j].ed,v[i][j].w);
    }
    return 0;
}