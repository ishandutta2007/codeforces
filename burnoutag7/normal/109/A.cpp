#include<bits/stdc++.h>
using namespace std;

int n;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("lsod.txt","w",stdout);
    cin>>n;
    for(int i=0;i*4<=n;i++){
        if((n-i*4)%7==0){
            for(int j=0;j<i;j++){
                cout<<4;
            }
            for(int j=0;j<(n-i*4)/7;j++){
                cout<<7;
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;

    return 0;
}