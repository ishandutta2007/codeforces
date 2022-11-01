#include<bits/stdc++.h>
using namespace std;

int n,a[100005],mn;
bool mark[100005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    mn=*min_element(a+1,a+1+n);
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(a[i]%mn==0){
            v.emplace_back(a[i]);
        }
        mark[i]=a[i]%mn==0;
    }
    sort(v.begin(),v.end());
    bool f=true;
    for(int i=1,j=0;i<=n;i++){
        if(mark[i]){
            a[i]=v[j++];
        }
        assert(j<=v.size());
        f&=a[i]>=a[i-1];
    }
    cout<<(f?"YES\n":"NO\n");
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        mian();
    }

    return 0;
}