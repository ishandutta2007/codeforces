#include<bits/stdc++.h>
using namespace std;

int n;
char s[55];

void mian(){
    cin>>n>>s+1;
    for(int i=1;i<n;i++)if(s[i]!=s[i+1]){
        cout<<i<<' '<<i+1<<'\n';
        return;
    }
    cout<<"-1 -1\n";
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