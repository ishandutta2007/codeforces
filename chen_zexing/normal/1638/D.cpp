#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
using namespace std;
int a[1005][1005],f[1005][1005];
struct node{
    int x,y,t;
};
vector <node> ans;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        queue <pair<int,int>> q;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                if(a[i][j]==a[i][j+1]&&a[i][j]==a[i+1][j]&&a[i][j]==a[i+1][j+1])
                    q.push(make_pair(i,j)),f[i][j]=1,ans.push_back(node{i,j,a[i][j]});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            int x=temp.first,y=temp.second;
            a[x][y]=a[x+1][y]=a[x][y+1]=a[x+1][y+1]=-1;
            for(int i=max(x-1,1);i<=min(x+1,n-1);i++)
                for(int j=max(y-1,1);j<=min(y+1,m-1);j++){
                    if(f[i][j]) continue;
                    vector <int> v;
                    for(int k=i;k<i+2;k++)
                        for(int l=j;l<j+2;l++)
                            if(a[k][l]!=-1) v.push_back(a[k][l]);
                    if(v.size()==0) continue;
                    sort(v.begin(),v.end());
                    //cout<<i<<" "<<j<<" "<<v[0]<<" "<<v.back()<<endl;
                    if(v[0]==v.back()){
                        q.push(make_pair(i,j)),f[i][j]=1,ans.push_back(node{i,j,v[0]});
                    }
                }
        }
        int fl=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]!=-1)
                    fl=1;
        if(fl) puts("-1");
        else{
            printf("%d\n",ans.size());
            reverse(ans.begin(),ans.end());
            for(auto t:ans) printf("%d %d %d\n",t.x,t.y,t.t);
        }
    }
    return 0;
}
//unordered_map