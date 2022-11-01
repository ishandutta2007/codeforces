#include<bits/stdc++.h>
using namespace std;

bool cmp1(const pair<pair<int,int>,int> &i,const pair<pair<int,int>,int> &j){
    if(i.first.second!=j.first.second)return i.first.second>j.first.second;
    return i.first.first<j.first.first;
}

bool cmp2(const pair<pair<int,int>,int> &i,const pair<pair<int,int>,int> &j){
    if(i.first.first!=j.first.first)return i.first.first>j.first.first;
    return i.first.second>j.first.second;
}

int n,p,k;
pair<pair<int,int>,int> a[100005];

int main(){

    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].first.first,&a[i].first.second);
        a[i].second=i;
    }
    sort(a+1,a+1+n,cmp1);
    sort(a+1,a+1+n-p+k,cmp2);
    for(int i=1;i<=k;i++){
        printf("%d ",a[i].second);
        a[i].second=-1;
    }
    sort(a+1,a+1+n-p+k,cmp1);
    p-=k;
    for(int i=1;i<=n;i++){
        if(k==0&&p-->0)printf("%d ",a[i].second);
        k-=a[i].second==-1;
    }

    return 0;
}