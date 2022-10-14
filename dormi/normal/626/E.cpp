#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
lli arr[MAXN];
int n;
long double calc(int mid, int am){
    return (long double)(arr[mid]-arr[mid-am-1]+arr[n]-arr[n-am])/(long double)(2*am+1)-(long double)(arr[mid]-arr[mid-1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1);
    for(int i=1;i<=n;i++)arr[i]+=arr[i-1];
    long double best=-1;
    int ind=-1,am=-1;
    for(int i=1;i<=n;i++){
        int lo=0,hi=min(i-1,n-i);
        while(lo!=hi){
            int mid=(lo+hi)/2+1;
            if(mid==0||calc(i,mid)>calc(i,mid-1))lo=mid;
            else hi=mid-1;
        }
        long double te=calc(i,lo);
        if(te>best){
            best=te,ind=i,am=lo;
        }
    }
    printf("%d\n",am*2+1);
    for(int i=ind-am;i<=ind;i++)printf("%lli ",arr[i]-arr[i-1]);
    for(int i=n-am+1;i<=n;i++)printf("%lli ",arr[i]-arr[i-1]);
    return 0;
}