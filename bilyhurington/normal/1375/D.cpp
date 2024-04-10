/*
 * @Author: BilyHurington
 * @Date: 2020-07-04 22:45:02
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-04 23:33:48
 */ 
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n,a[1010];
bool tag[1010];
int get_mex(){
    for(int i=1;i<=n;i++) if(a[i]<n) tag[a[i]]=1;
    int ans;
    for(int i=0;i<=n;i++) if(!tag[i]){ans=i;break;}
    for(int i=1;i<=n;i++) if(a[i]<n) tag[a[i]]=0;
    return ans;
}
bool check(){
    for(int i=1;i<=n;i++) if(a[i]!=i-1) return 0;
    return 1;
}
vector<int> vec;
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;vec.clear();
    for(int i=1;i<=n;i++) if(a[i]!=i-1) q.push(make_pair(a[i],i));
    int l;
    while(!check()){
        l=get_mex();//printf("%d\n",l);
        if(l!=n&&a[l+1]!=l) vec.push_back(l+1),a[l+1]=l;
        else{
            while(q.size()&&a[q.top().second]==q.top().second-1) q.pop();
            int x=q.top().second;q.pop();vec.push_back(x);
            a[x]=l;q.push(make_pair(a[x],x));
        }
        // for(int i=1;i<=n;i++) printf("%d ",a[i]);printf("\n");
    }
    printf("%d\n",vec.size());
    for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);printf("\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}