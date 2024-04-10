#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int f(int n){
    if(n==1 || n==0){
        return 1;
    }
    return n*f(n-1);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    int sum1=0,sum2=0,u=0,d;
    for(int i=0;i<s1.length();i++){
        if(s1[i]=='-'){
            sum1--;
        }else{
            sum1++;
        }
        if(s2[i]=='-'){
            sum2--;
        }else if(s2[i]=='+'){
            sum2++;
        }else{
            u++;
        }
    }
    cout<<fixed;
    d=sum1-sum2;
    for(int i=u*-1;i<=u;i+=2){
        if(i==d){
            double a=f(u)/f((i-(u*-1))/2)/f(u-((i-(u*-1))/2))/pow(2,u);
            cout<<setprecision(9)<<a;
            return 0;
        }
    }
    cout<<setprecision(9)<<0.0;
    return 0;
}