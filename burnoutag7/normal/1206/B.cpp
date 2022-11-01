#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a[100005];
ll cost;
int neg,fre;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cost+=min(abs(a[i]-1),abs(a[i]+1));
        if(abs(a[i]+1)<abs(a[i]-1)){
            neg++;
        }
        if(a[i]==0){
            fre++;
        }
    }
    if((neg&1)&&fre==0){
        cout<<cost+2<<endl;
    }else{
        cout<<cost<<endl;
    }

    return 0;
}