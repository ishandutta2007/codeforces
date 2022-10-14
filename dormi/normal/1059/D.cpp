#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e5+1;
pair<double,double> arr[MAXN];
double prec=1e-7;
int n;
bool work(double radi){
    double l=-1e16,r=1e16;
    for(int i=0;i<n;i++){
        if((radi-arr[i].second)*(radi-arr[i].second)>radi*radi)return false;
        double d=sqrt(2*(arr[i].second*radi)-(arr[i].second*arr[i].second));
        l=max(l,arr[i].first-d);
        r=min(r,arr[i].first+d);
    }
    if(l<=r+prec)return true;
    return false;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    int zecnt=0;
    int neg=0;
    int pos=0;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
        if(arr[i].second==0)zecnt++;
        else if(arr[i].second>0)pos++;
        else neg++;
        arr[i].second=abs(arr[i].second);
    }
    if(zecnt>1){
        printf("-1\n");
        return 0;
    }
    if(pos&&neg){
        printf("-1\n");
        return 0;
    }
    sort(arr,arr+n);
    double lo=0,hi=1e14;
    while((hi-lo)/(max((double)1,hi))>prec){
        double mid=(lo+hi)/2.0;
        if(work(mid))hi=mid;
        else lo=mid+prec;
    }
    printf("%f\n",lo);
    return 0;
}