#include <bits/stdc++.h>
using namespace std;
string s;
int a[100001];
int main(){
    cin>>s;
    for (int i=1;i<=s.size();++i){
        a[i]=s[i-1]-'0';
    }
    int number;
    for (int i=1;i<=s.size();++i){
            number=a[i];
                if (number%8==0) {cout<<"YES"<<endl<<number; return 0;}
        for (int j=i+1;j<=s.size();++j){
            number=a[i]*10+a[j];
                if (number%8==0) {cout<<"YES"<<endl<<number; return 0;}
            for (int k=j+1;k<=s.size();++k){
                number=a[i]*100+a[j]*10+a[k];
                if (number%8==0) {cout<<"YES"<<endl<<number; return 0;}
                }
    }}
    cout<<"NO";
}