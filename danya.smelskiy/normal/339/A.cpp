#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
int j;
int main(){
    cin>>s;
    for(int i=0;i<s.size();++i){
        if (i%2==0) ++j;
        if (s[i]=='1') a[j]=1;
        else if (s[i]=='2') a[j]=2;
        else if (s[i]=='3') a[j]=3;
    }
    sort(a+1,a+j+1);
    for (int i=1;i<j;++i){
        cout<<a[i]<<"+";
    }
    cout<<a[j];
}