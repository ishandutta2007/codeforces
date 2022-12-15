#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int b[100005][9],c[100005][9],v[100005],o[100005],op[100005],id[100005];
struct node{
    int p,id;
    friend bool operator <(node a,node b){
        return a.p<b.p;
    }
}p[100005];
int mn[512];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1,t;i<=n;i++){
            scanf("%d",&t);
            for(int j=1,x;j<=t;j++) scanf("%d",&x),b[i][x-1]=1,v[i]+=(1<<(x-1));
        }
        for(int i=0;i<512;i++) mn[i]=INT_MAX;
        for(int i=1,t;i<=m;i++){
            scanf("%d%d",&p[i].p,&t),p[i].id=i;
            op[i]=p[i].p;
            vector <int> temp;
            for(int j=1,x;j<=t;j++) scanf("%d",&x),c[i][x-1]=1,temp.push_back(x-1),o[i]+=(1<<(x-1));
            for(int j=0;j<(1<<temp.size());j++) {
                int now=0;
                for (int k = 0; k < temp.size(); k++)
                    if ((1 << k) & j) now+=(1<<temp[k]);
                if(mn[now]>p[i].p) mn[now]=p[i].p,id[now]=i;
            }
        }
        sort(p+1,p+m+1);
        int mx=-1,tot=INT_MAX,p1=-1,p2=-1;
        for(int i=0;i<512;i++){
            int cnt=0,f=0,mnc=INT_MAX,pos1=-1,pos2=-1;
            for(int j=1;j<=n;j++) if((v[j]&i)==v[j]) cnt++;
            for(int j=1;j<=m;j++){
                int nd=i-(o[j]&i);
                if(nd==0){
                    f=1;
                    if(op[j]==p[1].p){
                        if(mnc>p[2].p+op[j]) mnc=p[2].p+op[j],pos1=p[2].id,pos2=j;
                    }
                    else{
                        if(mnc>p[1].p+op[j]) mnc=p[1].p+op[j],pos1=p[1].id,pos2=j;
                    }
                }
                else{
                    if(mn[nd]!=INT_MAX){
                        f=1;
                        if(mnc>mn[nd]+op[j]) mnc=mn[nd]+op[j],pos1=id[nd],pos2=j;
                    }
                }
            }
            if(!f) continue;
            if(cnt>mx) mx=cnt,tot=mnc,p1=pos1,p2=pos2;
            else if(cnt==mx){
                if(mnc<tot) tot=mnc,p1=pos1,p2=pos2;
            }
        }
        //cout<<mx<<" "<<tot<<endl;
        printf("%d %d\n",p1,p2);
    }
    return 0;
}
//
/// 
//01
//