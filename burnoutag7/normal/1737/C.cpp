#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,ox[3],oy[3];
    cin>>n>>ox[0]>>oy[0]>>ox[1]>>oy[1]>>ox[2]>>oy[2];
    sort(ox,ox+3);
    sort(oy,oy+3);
    int sx=ox[1],sy=oy[1],ex,ey;
    cin>>ex>>ey;
    if((sx==1||sx==n)&&(sy==1||sy==n)){
        cout<<(ex==sx||ey==sy?"YES\n":"NO\n");
    }else{
        cout<<((sx+sy&1)!=(ex+ey&1)?"YES\n":(sx&1)==(ex&1)?"YES\n":"NO\n");
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