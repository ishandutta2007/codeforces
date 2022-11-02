#include <bits/stdc++.h>
using namespace std;

long long ans[50000];
long long nums[50000];

long long squares[25000000];

bool issquare(long long& sqrtval, long long val){
    auto it=lower_bound(squares,squares+25000000,val);
    if(*it!=val)return false;
    sqrtval=(it-squares);
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    for(long long i=0;i<25000000;++i){
        squares[i]=i*i;
    }
    int n;
    cin>>n;
    n>>=1;
    for(int i=0;i<n;++i){
        cin>>nums[i];
    }
    long long prev=0;
    for(int i=0;i<n;++i){
        long long past=prev;
        long long sqrtval,tmpans;
        bool b;
        do{
            ++prev;
        }while((b=(tmpans=prev*prev-past*past)<=1e13)&&!issquare(sqrtval,prev*prev+nums[i]));
        if(!b){
            cout<<"No\n";
            return 0;
        }
        ans[i]=tmpans;
        prev=sqrtval;
    }
    cout<<"Yes\n";
    for(int i=0;i<n;++i){
        cout<<ans[i]<<' '<<nums[i]<<' ';
    }
    cout<<'\n';
}