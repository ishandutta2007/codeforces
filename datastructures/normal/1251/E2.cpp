#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define int long long
using namespace std;
priority_queue <int>h;
int t,n,len[200005],ans;
vector <int>c[200005];
struct node{
    int val,num;
}a[200005];
bool cmp(node a,node b){
    return a.num<b.num;
}
signed main(){
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for (int i=1;i<=n;i++)c[i].clear();
        for (int i=1;i<=n;i++){
            scanf("%lld%lld",&a[i].num,&a[i].val);
            c[a[i].num].push_back(a[i].val);
        }
        sort(a+1,a+1+n,cmp);
        for (int i=1;i<n;){
            while(!h.empty())h.pop();
            int j=i;
            for (;j<n;j++){
                int len=c[j].size();
                for (int k=0;k<len;k++)h.push(c[j][k]);               
                if (h.empty())break;
                h.pop();
            }
            if (j==i){
                i++;
                continue;
            }
            while(!h.empty())ans+=h.top(),h.pop();
            i=j;
        }
        cout<<ans<<endl;
    }
    return 0;
}