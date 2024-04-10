#include<bits/stdc++.h>
using namespace std;

int n;
int c[2][2];

void mian(){
    cin>>n;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++){
        static char x;
        cin>>x;
        c[i&1][x-'0'&1]++;
    }
    if(n&1){
        if(c[1][1])cout<<"1\n";
        else cout<<"2\n";
    }else{
        if(c[0][0])cout<<"2\n";
        else cout<<"1\n";
    }
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