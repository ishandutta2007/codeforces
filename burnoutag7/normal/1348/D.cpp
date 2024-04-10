#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        n--;
        int cur=1;
        vector<int> v;
        while(n){
            if(2*cur>=n){
                v.push_back(n-cur);
                cur=n;
                n=0;
            }else
            if(2*cur<=n/2){
                v.push_back(cur);
                cur*=2;
                n-=cur;
            }else{
                v.push_back(n/2-cur);
                cur=n/2;
                n-=cur;
            }
        }
        cout<<v.size()<<endl;
        for(int &x:v)cout<<x<<' ';
        cout<<endl;
    }

    return 0;
}