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
int x[1005],y[1005],n;
int check(){
    for(int i=1;i<=n;i++) if(x[i]%2||y[i]%2) return 0;
    return 1;
}
int check2(){
    for(int i=1;i<=n;i++) if(x[i]%2==0||y[i]%2==0) return 0;
    return 1;
}
int check3(){
    for(int i=1;i<=n;i++) if(x[i]%2==0) return 0;
    return 1;
}
int check4(){
    for(int i=1;i<=n;i++) if(y[i]%2==0) return 0;
    return 1;
}
vector <int> v1,v2,v3;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    while(check()||check2()||check3()||check4()){
        if(check()) for(int i=1;i<=n;i++) x[i]/=2,y[i]/=2;
        else if(check2()) for(int i=1;i<=n;i++) x[i]--,y[i]--;
        else if(check3()) for(int i=1;i<=n;i++) x[i]--;
        else if(check4()) for(int i=1;i<=n;i++) y[i]--;
    }
    for(int i=1;i<=n;i++) {
        if (x[i] % 2 && y[i] % 2) v3.push_back(i);
        else if(x[i]%2||y[i]%2) v2.push_back(i);
        else v1.push_back(i);
    }
    if(!v1.size()&&!v3.size()){
        vector <int> v;
        for(int i=1;i<=n;i++) if(x[i]%2) v.push_back(i);
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
        puts("");
    }
    else if(!v1.size()||!v3.size()){
        printf("%d\n",v2.size());
        for(int i=0;i<v2.size();i++) printf("%d ",v2[i]);
        puts("");
    }
    else if(!v2.size()){
        printf("%d\n",v1.size());
        for(int i=0;i<v1.size();i++) printf("%d ",v1[i]);
        puts("");
    }
    else{
        printf("%d\n",v2.size());
        for(int i=0;i<v2.size();i++) printf("%d ",v2[i]);
        puts("");
    }
    return 0;
}