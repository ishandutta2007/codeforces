#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
template <class T> struct RIT :iterator<random_access_iterator_tag, T,lli,const T*,T>{
    T elt,skip;
    RIT(T t, T jump) : elt(t), skip(jump) {}
    bool operator == (const RIT &other) const { return elt == other.elt; }
    bool operator != (const RIT &other) const { return elt != other.elt; }
    T &operator * ()  { return elt; }
    RIT &operator ++ () { elt += skip; return *this; }
    RIT &operator += (lli am) { elt += am*skip; return *this; }
    RIT operator + (lli am) const { auto ret = RIT(elt + am * skip,skip); return ret; }
    lli operator - (const RIT& other) const{return (elt-other.elt)/skip;}
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        lli st,in,ex;
        cin>>st>>in>>ex;
        if(st+ex<=in)printf("0\n");
        else{
            lli mx=st+ex;
            lli mi=*lower_bound(RIT<lli>(st,1),RIT<lli>(mx+1,1),[&](lli mid){return mid>in+(ex-(mid-st));},[&](auto &lhs, auto f){
                return !f(lhs);
            });
            printf("%lli\n",mx-mi+1);
        }
    }
    return 0;
}