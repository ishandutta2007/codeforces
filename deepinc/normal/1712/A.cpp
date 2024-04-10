#include<bits/stdc++.h>
using namespace std;
int n,k;
struct xx{int i,x;}x[123];
bool cmp(xx a,xx b){return a.x<b.x||(a.x==b.x&&a.i<b.i);}
int main(){
    int t; cin>>t; while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i) scanf("%d",&x[i].x),x[i].i=i;
        sort(x+1,x+1+n,cmp);
        int c=0;
        for(int i=1;i<=k;++i) c+=x[i].i>k;
        printf("%d\n",c);
    }
}