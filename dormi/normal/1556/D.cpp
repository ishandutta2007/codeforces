#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
int queryor(int a, int b){
    printf("or %d %d\n",a,b);
    fflush(stdout);
    int x;
    cin>>x;
    if(x==-1)exit(0);
    return x;
}
int queryand(int a, int b){
    printf("and %d %d\n",a,b);
    fflush(stdout);
    int x;
    cin>>x;
    if(x==-1)exit(0);
    return x;
}
const int MN=1e4+1;
int arr[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    int bothhave=queryand(1,2);
    int sharedsomehow=queryor(1,2)-bothhave;
    int canda=queryand(1,3);
    int cora=queryor(1,3);
    int candb=queryand(2,3);
    int corb=queryor(2,3);
    int ashared=canda&sharedsomehow;
    sharedsomehow-=ashared;
    int bshared=candb&sharedsomehow;
    sharedsomehow-=bshared;
    int othashared=cora&sharedsomehow;
    sharedsomehow-=othashared;
    int othbshared=corb&sharedsomehow;
    sharedsomehow-=othbshared;
    arr[1]=bothhave|ashared|othashared;
    arr[2]=bothhave|bshared|othbshared;
    arr[3]=(cora-arr[1])|(canda);
    for(int i=4;i<=n;i++){
        arr[i]=(queryor(1,i)-arr[1])|queryand(1,i);
    }
    sort(arr+1,arr+1+n);
    printf("finish %d\n",arr[k]);
    fflush(stdout);
    return 0;
}