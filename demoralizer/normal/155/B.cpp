#include<bits/stdc++.h>
using namespace std;
int main(){
    vector <int> v;
    int n,s=0,c=1;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b>0){s+=a;c+=b-1;}
        else v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        if(c==0)break;
        s+=v[i];
        c--;
    }
    cout<<s;
}