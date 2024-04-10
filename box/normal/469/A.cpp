#include <iostream>
using namespace std;

bool ok[105];
int main() {
    int n,i; cin>>n; 
    cin>>i;while(i--){int v;cin>>v;ok[v]=true;}
    cin>>i;while(i--){int v;cin>>v;ok[v]=true;}
    bool x=1;
    for(int i=1;i<=n;i++)x=(x&&ok[i]);
    if(x)cout<<"I become the guy."<<endl;
    else cout<<"Oh, my keyboard!"<<endl;
}