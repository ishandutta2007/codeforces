#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=505;

int n;

int main(){
    cin>>n;
    int cx=1,cy=1;
    string a1,a2;
    for(int i=1;i<=n-1;i++){
        cout<<"? "<<cx+1<<' '<<cy<<' '<<n<<' '<<n<<endl;
        string ans;cin>>ans;
        if(ans=="YES")cx++,a1.push_back('D');
        else cy++,a1.push_back('R');
    }
    cx=n,cy=n;
    for(int i=1;i<=n-1;i++){
        cout<<"? "<<1<<' '<<1<<' '<<cx<<' '<<cy-1<<endl;
        string ans;cin>>ans;
        if(ans=="YES")cy--,a2.push_back('R');
        else cx--,a2.push_back('D');
    }
    reverse(a2.begin(),a2.end());
    cout<<"! "<<a1<<a2;
    return 0;
}