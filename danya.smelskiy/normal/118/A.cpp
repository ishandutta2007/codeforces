#include<bits/stdc++.h>
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned long long
#define sqr(a) ((a)*(a))
using namespace std;
string s;

int main(){
    cin>>s;
    for (int i=0;i<s.size();++i){
        if (s[i]>='A' && s[i]<='Z') s[i]+=32;
        if (s[i]!='a' && s[i]!='u' && s[i]!='o' && s[i]!='e' && s[i]!='i' && s[i]!='y') cout<<"."<<s[i];
    }
}