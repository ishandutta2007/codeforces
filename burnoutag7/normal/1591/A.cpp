#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,p=-1,c,h=1;
    cin>>n;
    while(n--){
        cin>>c;
        if(h==-1)continue;
        if(!p&&!c)h=-1;
        else if(p==1&&c)h+=5;
        else if(c)h++;
        p=c;
    }
    cout<<h<<'\n';
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