#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char c[500];
    cin>>c;
    int l=strlen(c);
    if(c[0]=='@'||c[l-1]=='@'){
        boo:;
        cout<<"No solution";
        return 0;
    }
    vc<int> v;
    for(int i=0;i<l;i++){
        if(c[i]=='@')v.pb(i);
    }
    if(v.size()==0)goto boo;
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]-v[i]<3)goto boo;
    }
    int a=0,d=0;
    for(int i=0;i<l;i++){
        cout<<c[i];
        if(a){cout<<",";a=0;}
        if(c[i]=='@'&&d<v.size()-1){a=1;d++;}
    }
}