#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        vector<pair<int,int>>V;
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=2;i<=n;i++)V.push_back(make_pair(max(0,a[i-1]-a[i]),i));
        sort(V.begin(),V.end());
        printf("1");
        for(i=0;i<V.size();i++)printf(" %d",V[i].second);
        puts("");
    }
}