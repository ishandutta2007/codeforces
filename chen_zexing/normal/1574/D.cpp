#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int n;
struct node{
    int a[11],sum;
    friend bool operator <(node a,node b){
        if(a.sum!=b.sum) return a.sum<b.sum;
        for(int i=1;i<=n;i++) if(a.a[i]!=b.a[i]||i==n) return a.a[i]<b.a[i];
    }
};
int a[11][200005],c[11];
map <node,int> mp;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int m;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>c[i];
            for(int j=1;j<=c[i];j++) scanf("%d",&a[i][j]);
        }
        cin>>m;
        for(int i=1;i<=m;i++){
            node temp;
            temp.sum=0;
            memset(temp.a,0,sizeof(temp.a));
            for(int j=1;j<=n;j++) scanf("%d",&temp.a[j]),temp.sum+=a[j][temp.a[j]];
            mp[temp]=1;
            //cout<<temp.sum<<endl;
        }
        priority_queue <node> q;
        node st;
        st.sum=0;
        memset(st.a,0,sizeof(st.a));
        for(int i=1;i<=n;i++) st.a[i]=c[i],st.sum+=a[i][c[i]];
        q.push(st);
        while(!q.empty()){
            node temp=q.top();
            //cout<<mp[temp]<<" "<<temp.sum<<endl;
            //for(int i=1;i<=n;i++) printf("%d ",temp.a[i]);
            if(!mp[temp]){
                for(int i=1;i<=n;i++) printf("%d ",temp.a[i]);
                puts("");
                exit(0);
            }
            q.pop();
            int lim=n;
            for(int i=1;i<=n;i++) if(temp.a[i]!=c[i]){
                    lim=i;
                    break;
                }
            for(int i=lim;i>=1;i--){
                if(temp.a[i]>1){
                    node nxt=temp;
                    nxt.a[i]--,nxt.sum=temp.sum-a[i][temp.a[i]]+a[i][nxt.a[i]];
                    q.push(nxt);
                }
            }
        }
    }
    return 0;
}
//
/// 
//01
//