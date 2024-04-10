#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
int n,m,k;
vector<pair<int,char> >v;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    if(k>4*n*m-2*n-2*m)puts("NO"),exit(0);
    puts("YES");
    for(int i=1;i<n;i++){
        int dat=min(k,m-1);
        if(dat)v.pb(mp(dat,'R')),k-=dat;
        dat=min(k,m-1);
        if(dat)v.pb(mp(dat,'L')),k-=dat;
        if(!k)break;
        v.pb(mp(1,'D')),k--;
    }
    int dat=min(k,m-1);
    if(dat)v.pb(mp(dat,'R')),k-=dat;
    for(int i=1;i<m;i++){
        int dat=min(k,n-1);
        if(dat)v.pb(mp(dat,'U')),k-=dat;
        dat=min(k,n-1);
        if(dat)v.pb(mp(dat,'D')),k-=dat;
        if(!k)break;
        v.pb(mp(1,'L')),k--;
    }
    if(k)v.pb(mp(k,'U')),k-=dat;
    printf("%d\n",v.size());
    for(int i=0;i<v.size();i++)printf("%d %c\n",v[i].first,v[i].second);
    return 0;
}