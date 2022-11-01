#include<bits/stdc++.h>
using namespace std;

void mian(){
    string s;
    int a=0,b=0;
    cin>>s;
    for(char c:s){
        a=a*10+c-'0';
        swap(a,b);
    }
    cout<<(a+1)*(b+1)-2<<'\n';
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