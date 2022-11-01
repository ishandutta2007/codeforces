#include<bits/stdc++.h>
using namespace std;

int T,p1,p2,p3,mn;
string s;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        p1=p2=p3=-1e9;
        mn=1e9;
        cin>>s;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')p1=i;
            if(s[i]=='2')p2=i;
            if(s[i]=='3')p3=i;
            mn=min(mn,i-min({p1,p2,p3})+1);
        }
        cout<<(mn==1e9?0:mn)<<endl;
    }

    return 0;
}