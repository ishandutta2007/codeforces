#include <bits/stdc++.h>
using namespace std;
long long n,k,l,z;
string s;
long long last,kol;
vector<long long> v;
int main(){
    cin>>n>>k>>l>>z;
    cin>>s;
    //l=l/2+1;
    for (int i=0;i<s.size();++i){
        if (s[i]=='0'){
            ++last;
            if (last%l==0){ ++kol; v.push_back(i+1);}
        } else last=0;
    }
    cout<<kol-k+1<<'\n';
    for (int i=0;i<kol-k+1;++i)
        cout<<v[i]<<" ";
}