#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
    int c=0;
    char a[3][3][3][3];
    for(int i=0;i<11;i++){
        string temp;
        getline(cin,temp);
        if((i+1)%4!=0){
            for(int o=0;o<11;o++){
                if((o+1)%4!=0){
                    a[o%4][i%4][o/4][i/4]=temp[o];
                }
            }
        }
    }
    int n,m;
    cin>>n>>m;
    n=n%3;
    if(n==0) n=2;
    else if(n==1) n=0;
    else n=1;
    m=m%3;
    if(m==0) m=2;
    else if(m==1) m=0;
    else m=1;
    bool k=true;
    for(int i=0;i<3;i++){
        for(int o=0;o<3;o++){
            if(a[i][o][m][n]=='.'){
                a[i][o][m][n]='!';
                k=false;
            }
        }
    }
    if(k){
        for(int i=0;i<3;i++){
            for(int o=0;o<3;o++){
                for(int p=0;p<3;p++){
                    for(int u=0;u<3;u++){
                        if(a[p][u][i][o]=='.'){
                            a[p][u][i][o]='!';
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<11;i++){
        if((i+1)%4==0){
            cout<<"\n";
            continue;
        }
        if((i+1)%4!=0){
            for(int o=0;o<11;o++){
                if((o+1)%4==0){
                    cout<<' ';
                    continue;
                }
                if((o+1)%4!=0){
                    cout<<a[o%4][i%4][o/4][i/4];
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}