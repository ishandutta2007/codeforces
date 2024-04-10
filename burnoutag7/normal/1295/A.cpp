#include<bits/stdc++.h>
using namespace std;

int t;
int n;
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n;
        v.clear();
        while(n>=2){
            n-=2;
            v.push_back(1);
        }
        for(int i=0;n>0&&i<v.size();i++){
            if(n>=4){
                n-=4;
                v[i]=9;
                continue;
            }
            if(n>=1){
                n-=1;
                v[i]=7;
                continue;
            }
        }
        for(int i=0;i<v.size();i++)cout<<v[i];
        cout<<endl;
    }

    return 0;
}