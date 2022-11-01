#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int> p;
    for(int i=n;i>=1;i--)if(i!=a&&i!=b)p.emplace_back(i);
    if(n>2&&(*min_element(p.begin(),p.begin()+n/2-1)<a||*max_element(p.begin()+n/2-1,p.end())>b)){
        cout<<"-1\n";
    }else{
        for(int i=1,j=0;i<=n;i++){
            cout<<(i==1?a:i==n?b:p[j++])<<' ';
        }
        cout<<'\n';
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