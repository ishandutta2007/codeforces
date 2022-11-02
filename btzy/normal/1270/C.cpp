#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n;
        cin>>n;
        long long sum=0,pxor=0;
        for(int i=0;i<n;++i){
            long long tmp;
            cin>>tmp;
            sum+=tmp;
            pxor^=tmp;
        }
        pxor<<=1;
        long long diff=0;
        for(long long i=1;sum!=pxor;i<<=1){
            if((sum&i)!=(pxor&i)){
                diff|=i;
                sum+=i;
                pxor^=(i<<1);
            }
        }
        cout<<"1\n"<<diff<<'\n';
    }
}