#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=3030;
int n,k,nn,sum;char s[N];bool fl;
vector<int>v[N];
int main(){
    scanf("%d%d%s",&n,&k,s+1);
    for(nn=1;;nn++){
        for(int i=1;i<n;i++)if(s[i]=='R'&&s[i+1]=='L')v[nn].pb(i),sum++;
        if(!v[nn].size()){nn--;break;}
        for(int i=0;i<v[nn].size();i++)swap(s[v[nn][i]],s[v[nn][i]+1]);
    }
    if(nn>k||sum<k)puts("-1"),exit(0);
    for(int i=1;i<=nn;i++){
        int p=min((int)v[i].size(),sum-k+1);
        printf("%d ",p);k--;
        for(int j=0;j<p;j++)printf("%d ",v[i][j]);
        puts("");
        for(int j=p;j<v[i].size();j++)printf("1 %d\n",v[i][j]),k--;
        sum-=v[i].size();
    }
    return 0;
}