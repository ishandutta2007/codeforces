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
int d[200005],dd[200005],a[200005],n;
vector <int> v[200005];
void bfs(int x){
    queue <int> q;
    q.push(x),d[x]=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
            if(d[v[temp][i]]==0&&v[temp][i]!=1)
                q.push(v[temp][i]),d[v[temp][i]]=d[temp]+1;
    }
}
void bfs2(int x){
    queue <int> q;
    q.push(x),dd[x]=0;
    while(!q.empty()){
        int temp=q.front();
        q.pop();
        for(int i=0;i<v[temp].size();i++)
            if(dd[v[temp][i]]==0&&v[temp][i]!=n)
                q.push(v[temp][i]),dd[v[temp][i]]=dd[temp]+1;
    }
}
bool cmp(int a,int b){
    return dd[a]>dd[b];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int m,k;
        cin>>n>>m>>k;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs(1);
        bfs2(n);
        sort(a+1,a+k+1,cmp);
        int ans=0;
        for(int i=1;i<k;i++){
            int l=1,r=k;
            while(l<r){
                int mid=(l+r)>>1;
                if(dd[a[mid]]>dd[a[i]]) l=mid+1;
                else r=mid;
            }
            if(l==i) l++;
            ans=max(ans,d[a[i]]+dd[a[l]]+1);
            //cout<<ans<<endl;
        }
        printf("%d\n",min(d[n],ans));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp