#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string s1;
int a[2000];
int main(){
    cin>>n;
    cin>>s;
    for (int i=0;i<s.size();++i)
        ++a[s[i]-'a'];
    for (int i=0;i<=25;++i){
        if (a[i]%n==0){
            for(int j=1;j<=a[i]/n;++j)
                s1=s1+(char)(97+i);
        } else {
        cout<<"-1";
        return 0;}
    }
    for(int i=1;i<=n;++i)
        cout<<s1;
}