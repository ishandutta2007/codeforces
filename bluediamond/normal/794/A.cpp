#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int poz,st,dr;
int n,v[100005],sol=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>poz>>st>>dr;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(st<x && x<dr){
            sol++;
        }
    }
    cout<<sol<<"\n";
    return 0;
}