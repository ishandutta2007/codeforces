#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;int k;
int ar[300005];
int okk(int mxx){
    vector<int>ok;
    ok.push_back(0);
    for(int i=k;i<=n;i++){
        if(ar[i]-ar[i-k+1]>mxx){continue;}
        int l=1;int r=i-k+1;
        while(l<r){
            int mi=(l+r)/2;
            if(ar[i]-ar[mi]<=mxx){
                r=mi;
            }else{
                l=mi+1;
            }
        }
        int pl=lower_bound(ok.begin(),ok.end(),l-1)-ok.begin();
        if(pl==ok.size()||ok[pl]>=i-k+1){continue;}
        ok.push_back(i);
    }
    if(ok.back()==n){return 1;}
    return 0;
}



signed main()
{

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf(" %lld",&ar[i]);
    }
    sort(ar+1,ar+n+1);
    int l=0;int r=2e9;
    while(l<r){
        int mi=(l+r)/2;
        if(okk(mi)){
            r=mi;
        }else{
            l=mi+1;
        }
    }
    cout<<l<<endl;


}