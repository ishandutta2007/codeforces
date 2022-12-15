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
int a[100005],b[100005],h[100005];
struct pos{
    int x,y;
};
vector <pos> v;
set <int> r1;
struct col{
    int y,type;
    friend bool operator <(col a,col b){
        return a.type<b.type||a.type==b.type&&a.y<b.y;
    }
};
set <col> r2;
int r[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,x=0,f=1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]) b[++x]=i;
        }
        if(a[b[x]]>1) f=0;
        if(f==0){
            puts("-1");
            continue;
        }
        for(int i=x;i>=1;i--){
            int y=b[i],t=a[b[i]];
            //cout<<y<<endl;
            if(t==1){
                v.push_back(pos{y,y});
                r1.insert(y);
                r2.insert(col{y,1});
                r[y]=y;
            }
            else if(t==2){
                if(r1.size()){
                    int temp=*r1.begin();
                    v.push_back(pos{r[temp],y});
                    r1.erase(r1.find(temp));
                    r2.erase(r2.find(col{temp,1}));
                    r[y]=r[temp];
                    r2.insert(col{y,0});
                }
                else{
                    f=0;
                    break;
                }
            }
            else{
                if(r2.size()){
                    col temp=*r2.begin();
                    v.push_back(pos{y,y});
                    v.push_back(pos{y,temp.y});
                    if(r1.find(temp.y)!=r1.end()) r1.erase(r1.find(temp.y));
                    r2.erase(r2.find(temp));
                    r[y]=y;
                    r2.insert(col{y,0});
                }
                else{
                    f=0;
                    break;
                }
            }
        }
        if(!f){
            puts("-1");
            continue;
        }
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++) printf("%d %d\n",v[i].x,v[i].y);
    }
    return 0;
}