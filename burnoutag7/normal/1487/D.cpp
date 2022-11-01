#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    cin>>n;
    int x=sqrt(2*n-1);
    while(x*x>2*n-1)x--;
    while((x+1)*(x+1)<=2*n-1)x++;
    cout<<(x-1>>1)<<'\n';
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