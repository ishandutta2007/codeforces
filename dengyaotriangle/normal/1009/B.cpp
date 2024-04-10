#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

char x[maxn];
int n,c;

int main(){
    cin>>x;
    n=strlen(x);
    for(int i=0;i<n;i++)if(x[i]=='1') c++;
    for(int i=0;i<n;i++){
        if(x[i]=='1') continue;
        if(x[i]=='2'){
            while((c--)>0) cout<<'1';
        }
        cout<<x[i];
    }
    while((c--)>0) cout<<'1';
    return 0;
}