#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,a;
    long long sum=0;
    cin>>n;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>a;
        sum+=a;
        f&=(i-1)*i/2<=sum;
    }
    cout<<(f?"yEs\n":"nO\n");
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}