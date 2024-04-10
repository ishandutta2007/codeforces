#include<bits/stdc++.h>

using namespace std;

int r[7]={0,4,8,15,16,23,42};

int main(){//lmyakioi
    int a1,a2,a3,a4;
    cout<<"? 1 2"<<endl;
    fflush(stdout);
    cin>>a1;
    cout<<"? 2 3"<<endl;
    fflush(stdout);
    cin>>a2;
    cout<<"? 3 4"<<endl;
    fflush(stdout);
    cin>>a3;
    cout<<"? 4 5"<<endl;
    fflush(stdout);
    cin>>a4;
    while(1){
        if(r[1]*r[2]==a1&&r[2]*r[3]==a2&&r[3]*r[4]==a3&&r[4]*r[5]==a4){
            cout<<"! "<<r[1]<<' '<<r[2]<<' '<<r[3]<<' '<<r[4]<<' '<<r[5]<<' '<<r[6];
            return 0;
        }
        next_permutation(r+1,r+7);
    }
    return 0;
}