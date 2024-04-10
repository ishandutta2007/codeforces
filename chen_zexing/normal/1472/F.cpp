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
struct block{
    int x,y;
}a[200005];
bool cmp(block a,block b){
    return a.y<b.y;
}
unordered_map <long long ,int> mp;
long long ch(block a){
    return 1LL*a.x*1e9+a.y;
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        mp.clear();
        for(int i=1;i<=m;i++) scanf("%d%d",&a[i].x,&a[i].y),mp[ch(a[i])]=1;
        mp[ch(block{1,n+1})]=mp[ch(block{2,n+1})]=1;
        sort(a+1,a+m+1,cmp);
        a[m+1].y=n+1;
        int f=1;
        for(int i=1;i<=m;i++){
            int y=a[i].y;
            //cout<<a[i].x<<" "<<a[i].y<<endl;
            if(mp[ch(block{1,a[i].y})]&&mp[ch(block{2,a[i].y})]) continue;
            int nxt=a[i+1].y;
            if(nxt==y+1){
                if(mp[ch(block{3-a[i].x,a[i].y+1})]){
                    f=0;
                    break;
                }
                else i++;
            }
            else{
                if((nxt-y)%2==0) a[i].x=3-a[i].x;
                a[i].y=nxt-1;
                i--;
            }
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}