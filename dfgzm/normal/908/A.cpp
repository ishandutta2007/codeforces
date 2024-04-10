#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k,n,m;
int main(){
    string S;
    cin>>S;
    for(i=0;i<S.size();i++){
        if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u')++k;
        if(S[i]=='1' || S[i]=='3' || S[i]=='5' || S[i]=='7' || S[i]=='9')++k;
    }cout<<k<<endl;
}//