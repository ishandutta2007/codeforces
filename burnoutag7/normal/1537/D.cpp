#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,c=0;
    cin>>n;
    while(n%2==0){
        n/=2;
        c++;
    }
    cout<<(c&&(c%2==0||n!=1)?"Alice\n":"Bob\n");
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