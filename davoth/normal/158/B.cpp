#include <iostream>
using namespace std;
int main(){
    int n,temp,s1=0,s2=0,s3=0,c=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        switch(temp){
        case 1:
            s1++;
            break;
        case 2:
            s2++;
            break;
        case 3:
            s3++;
            break;
        case 4:
            c++;
            break;
        }
    }
    while(s1>0&&s3>0){
        s1--;
        s3--;
        c++;
    }
    while(s2>1){
        s2-=2;
        c++;
    }
    while(s2>0&&s1>1){
        s1-=2;
        s2--;
        c++;
    }
    while(s1>3){
        s1-=4;
        c++;
    }
    while(s1>0&&s2>0){
        c++;
        s1--;
        s2--;
    }
    while(s1>2){
        c++;
        s1-=3;
    }
    while(s1>1){
        c++;
        s1-=2;
    }
    c+=s1+s2+s3;
    cout<<c;
    return 0;
}