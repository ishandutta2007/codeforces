#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T,n;
vector<ll> v;

int main(){

    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        v.clear();
        v.push_back(n);
        while(v.back()>1){
            ll l=1,r=n,m,res;
            while(l<=r){
                m=(l+r)>>1;
                if(n/m<v.back()){
                    res=m;
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            v.push_back(n/res);
        }
        v.push_back(0);
        reverse(v.begin(),v.end());
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++){
            printf("%d ",v[i]);
        }
        puts("");
    }

    return 0;
}