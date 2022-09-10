#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100010
int a[SIZE],b[SIZE],nn;
vector<int>list[SIZE],p;
int get(int x){
    int tmp=lower_bound(p.begin(),p.end(),x)-p.begin();
    if(tmp!=p.size()&&p[tmp]==x)return tmp;
    return -1;
}
int main(){
    int i,j,k,n,m;
    cin>>n>>m;
    for(i=1;i<=n;i++){scanf("%d",&a[i]);b[i-1]=a[i];}
    sort(b,b+n);
    for(i=0;i<n;i+=j){
        for(j=1;i+j<n&&b[i]==b[i+j];j++);
        if(j>=b[i])p.pb(b[i]);
    }
    for(i=1;i<=n;i++){
        int now=get(a[i]);
        if(now!=-1)list[now].pb(i);
    }
    while(m--){
        int ll,rr,an=0;
        scanf("%d%d",&ll,&rr);
        for(i=0;i<p.size()&&ll+p[i]<=rr+1;i++){
            int v1=lower_bound(list[i].begin(),list[i].end(),ll)-list[i].begin();
            if(v1+p[i]>list[i].size())continue;
            if(list[i][v1+p[i]-1]>rr)continue;
            if(v1+p[i]==list[i].size()||list[i][v1+p[i]]>rr)an++;
        }
        printf("%d\n",an);
    }
    return 0;
}