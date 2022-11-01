#include<bits/stdc++.h>
using namespace std;

int n,x,a,odd,even;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>x;
        odd=even=0;
        for(int i=0;i<n;i++){
            cin>>a;
            if(a&1)odd++;
            else even++;
        }
        if(!(x==n&&(odd&1^1))&&odd&&!(odd==n&&(x&1^1))){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }

    return 0;
}