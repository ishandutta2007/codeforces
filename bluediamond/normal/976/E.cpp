#include <bits/stdc++.h>
using namespace std;
const long long N=200000;
long long n,a,b;
struct info{
    long long x,y;
};
info v[N+5];
bool cmp(info a,info b){
    long long da=a.x-a.y;
    long long db=b.x-b.y;
    return da>db;
}
long long sum=0,last=0,cur=0;
long long best=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b;
    for(long long i=1;i<=n;i++)
        cin>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    sum=0;
    for(long long i=1;i<=n;i++)
        sum+=v[i].y;
    best=sum;
    sum=0;
    for(long long i=1;i<=n;i++){
        if(cur<b && v[i].x>v[i].y){
            sum+=v[i].x;
            cur++;
            last=i;
        }
        else
            sum+=v[i].y;
    }
    if(b==0){
        cout<<sum;
        return 0;
    }
    for(long long i=1;i<=n;i++){
        long long nou=(long long)v[i].x*(1<<a),fara=0,val;
        if(i<=last){
            fara=sum-v[i].x;
            val=fara+nou;
        }
        else{
            fara=sum-v[i].y;
            val=fara+nou;
            if(last>=b)val-=(v[last].x-v[last].y);
        }
        best=max(best,val);
    }
    cout<<best;
    return 0;
}
/**

**/