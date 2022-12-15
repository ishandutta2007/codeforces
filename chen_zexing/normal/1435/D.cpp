#include <stdio.h>
#include<iostream>
#include<string>
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
using namespace std;
struct query{
    int t,v;
}a[200005];
int ans[200005];
struct qq{
    int v;
    friend bool operator <(qq a,qq b){
        return a.v>b.v;
    }
};
priority_queue <qq> p;
stack<int>q;
int main() {
    int n;
    scanf("%d\n",&n);
    for(int i=1;i<=n*2;i++){
        char c;
        scanf("%c",&c);
        if(c!='+'&&c!='-'){
            i--;
            continue;
        }
        if(c=='+') a[i].t=1;
        else{
            a[i].t=2;
            scanf("%d",&a[i].v);
        }
    }
    int cnt=0,f=1;
    for(int i=1;i<=n*2;i++){
        if(a[i].t==1) cnt++;
        else cnt--;
        if(cnt<0){
            f=0;
            break;
        }
        if(a[i].t==2&&a[i-1].t==2&&a[i].v<a[i-1].v){
            f=0;
            break;
        }
    }
    if(!f){
        puts("NO");
        return 0;
    }
    for(int i=1;i<=n*2;i++){
        if(a[i].t==1) q.push(i);
        else{
            ans[q.top()]=a[i].v;
            q.pop();
        }
    }
    f=1;
    for(int i=1;i<=n*2;i++){
        if(ans[i]) p.push(qq{ans[i]});
        else{
            if(p.top().v!=a[i].v){
                //cout<<p.top().v<<endl;
                f=0;
                break;
            }
            p.pop();
        }
    }
    if(!f) puts("NO");
    else {
        puts("YES");
        for (int i = 1; i <= n * 2; i++) {
            if (ans[i]) printf("%d ", ans[i]);
        }
    }
    return 0;
}