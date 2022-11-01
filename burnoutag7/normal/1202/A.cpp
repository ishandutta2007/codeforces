#include<bits/stdc++.h>
using namespace std;

string x,y;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>x;
        cin>>y;
        int cx=0,cy=0;
        for(int i=y.size()-1;i>=0;i--){
            if(y[i]=='1'){
                break;
            }else{
                cy++;
            }
        }
        for(int i=x.size()-1-cy;i>=0;i--){
            if(x[i]=='1'){
                break;
            }else{
                cx++;
            }
        }
        cout<<cx<<endl;
    }

    return 0;
}