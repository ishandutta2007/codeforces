#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

int a,b;
long long mi=0x7fffffff7fffffff,mk;

void chk(int h){
    //a+c=kg
    long long mia=((a+h-1)/h)*h;
    long long cur=(mia)*(b+mia-a)/h;
    long long k=mia-a;
    if(cur<mi){
        mi=cur;mk=k;
    }else if(cur==mi&&k<mk) mk=k;
}
int main(){
    cin>>a>>b;
    if(a<b)swap(a,b);
    int g=a-b;
    if(g==0){
        cout<<0;
        return 0;
    }
    for(int i=1;i*i<=g;i++){
        if(g%i==0){
            chk(i);
            chk(g/i);
        }
    }
    cout<<mk;
    return 0;
}