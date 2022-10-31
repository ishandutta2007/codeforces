#include <bits/stdc++.h>
using namespace std;
int n;
int first,last,x;
int a[100001];
long long ans;
bool t;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        a[i]=x;
        if (a[i]==1) { last=i; if (t==false) { t=true; first=i;}}
    }
    for (int i=first;i<=last;++i){
        if (a[i]==1) ++ans;
        else {
            if (a[i-1]==1 && a[i+1]==1) ++ans;

        }
    }
    cout<<ans;
}