#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    printf("%d",(s[s.length()-1]-'0')%2);
}