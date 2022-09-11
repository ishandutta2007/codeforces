#include<iostream>
using namespace std;
main(){
    unsigned long long A,B,two=1,an1=0,an2=0;
    cin>>A>>B;
    while(A||B){
        if((A&1)!=(B&1))break;
        if(A&1){
            an2+=two;
        }
        else{
            if((B&2)!=(A&2)){
                an1+=two;
                an2+=two;
                A-=2;
            }
        }
        A>>=1;
        B>>=1;
        two<<=1;
    }
    if(A||B)cout<<"-1\n";
    else cout<<an1<<" "<<an2<<endl;
}