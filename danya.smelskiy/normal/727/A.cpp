#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int a,b,ans;
int main(){
    cin>>a>>b;
    while (b!=a){
        if (b<a){
            cout<<"NO";
            return 0;
        }
        if (b%2==0){
            v.push_back(b);
            b/=2;
            ++ans;
        } else if (b%10==1){
            v.push_back(b);
            b/=10;
            ++ans;
        } else {
            cout<<"NO";
            return 0;
        }
    }
    v.push_back(a);
    ++ans;
    cout<<"YES"<<endl;
    cout<<ans<<endl;
    for (int i=v.size()-1;i>=0;--i)
        cout<<v[i]<<" ";
}