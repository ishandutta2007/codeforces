#include<bits/stdc++.h>
using namespace std;

int n,t;
int s[105],d[105];
int mn,pos;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>t;
    mn=1e9;
    for(int i=1;i<=n;i++){
        cin>>s[i]>>d[i];
        int cur=s[i];
        while(cur<t)cur+=d[i];
        if(mn>cur-t){
            mn=cur-t;
            pos=i;
        }
    }
    cout<<pos<<endl;

    return 0;
}