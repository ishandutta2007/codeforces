#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        lli x,y,x1,y1,x2,y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if((a||b)&&!(x-x1)&&!(x2-x)){
            printf("NO\n");
            continue;
        }
        if((c||d)&&!(y-y1)&&!(y2-y)){
            printf("NO\n");
            continue;
        }
        if(b>a)swap(a,b),swap(x1,x2);
        if(d>c)swap(d,c),swap(y1,y2);
        if(a-b<=abs(x-x1)&&c-d<=abs(y-y1))printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}