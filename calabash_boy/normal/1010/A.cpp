#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
int a[maxn],b[maxn],n,m;
typedef long double db;
bool check(db st){
    for (int i=0;i<n;i++){
        db now = st+m;
        db cost = now/a[i];
        if (cost>st)return false;
        st-=cost;
        now = st+m;
        cost = now/b[(i+1)%n];
        if (cost>st)return false;
        st-=cost;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for (int i=0;i<n;i++){
        scanf("%d",b+i);
    }
    db l =0,r = 2000000000;
    while (r-l>1e-6){
        db mid = (l+r)/2;
       // cout<<mid<<endl;
        if (check(mid)){
            r = mid;
        } else{
            l = mid;
        }
    }
    if (l>1e9){
        puts("-1");
        return 0;
    }
    if (check(l)){
        printf("%.9lf\n",(double)l);
    }else if (check(r)){
        printf("%.9lf\n",(double)r);
    }else{
        puts("-1");
    }
    return 0;
}