#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v){
    for(int i=0;i+1<v.size();i++)cout<<v[i]<<'.';
    cout<<v.back()<<'\n';
}

void mian(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=1,a;i<=n;i++){
        cin>>a;
        if(a==1)v.emplace_back(1);
        else{
            while(v.back()+1!=a)v.pop_back();
            v.back()=a;
        }
        print(v);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}