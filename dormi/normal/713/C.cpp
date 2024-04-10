#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
struct slopefunc{
    lli m,b;
    priority_queue<lli> points;
    slopefunc(lli m1, lli b1, vector<lli> pts){
        m=m1,b=b1;
        for(lli x:pts)points.push(x);
    }
    void merge(slopefunc a){
        m+=a.m,b+=a.b;
        while(sz(a.points)){
            points.push(a.points.top());
            a.points.pop();
        }
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli a;
    slopefunc cur(0,0,{});
    for(int i=0;i<n;i++){
        cin>>a;
        a-=i;
        cur.merge(slopefunc(1,-a,{a,a}));
        cur.b+=cur.points.top();
        cur.m-=1;
        cur.points.pop();
    }
    printf("%lli\n",cur.b);
    return 0;
}