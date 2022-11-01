#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m,a;
    cin>>n>>m;
    while(n--){
        cin>>a;
        m-=a;
    }
    cout<<(m?"NO":"YES")<<endl;
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