#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e6+1;
lli bit[MAXN];
bool good[(int)1e5+1];
void update(int loc){
    for(;loc<MAXN;loc+=loc&-loc){
        bit[loc]+=1;
    }
}
lli query(int loc){
    lli ans=0;
    for(;loc>0;loc-=loc&-loc)ans+=bit[loc];
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    pii vals[n];
    rep(i,0,n){
        int l;
        sc(l);
        int in;
        vector<int> arr;
        int minval=INT_MAX;
        rep(j,0,l){
            sc(in);
            if(in>minval)good[i]=true;
            minval=min(minval,in);
            arr.push_back(in);
        }
        sort(arr.begin(),arr.end());
        if(!good[i])update(arr[0]+1);
        vals[i]={arr[0],arr.back()};
    }
    lli am=0;
    lli goodcnt=0;
    rep(i,0,n){
        if(good[i]){
            goodcnt++;
            am+=(lli)2*(lli)n-(lli)1;
        }
        else{
            am+=query(vals[i].second);
        }
    }
    am-=goodcnt*(goodcnt-1);
    prl(am);
    return 0;
}