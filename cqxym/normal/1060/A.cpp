#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ct=0,d=n/11;
    for(register int i=0;i!=n;i++){
        if(s[i]=='8'){
            ct++;
        }
    }
    printf("%d",ct<d?ct:d);
    return 0;
}