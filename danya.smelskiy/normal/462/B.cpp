#include <bits/stdc++.h>
using namespace std;

long long n,k,last,kol[200];
long long ans;
char a[1000001];
string s;
inline bool cmp(char a,char b){
    if (kol[a]!=kol[b]) return kol[a]>kol[b];
    else return a>b;
}
int main(){
    cin>>n>>k;
    cin>>s;
    for (int i=0;i<s.size();++i){
        ++kol[s[i]];
        a[i+1]=s[i];
    }
    sort(a+1,a+s.size()+1,cmp);
    for (int i=1;i<=k;++i){
        if (a[i]==a[i-1]){
            ++last;
        } else {
            ans+=last*last;
            last=1;
        }
    }
    ans+=last*last;
    cout<<ans;;
}