#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int conv(int m,int d){
    for(int i=1;i<m;i++){
        switch(i){
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                d+=31;break;
            case 2:
                d+=28;break;
            default:
                d+=30;
        }
    }
    return d;
}
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    map<int,int> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a=conv(a,b);
        for(int i=1;i<=d;i++){
            m[a-i]+=c;
        }
    }
    int k=0;
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++){
        k=max(k,i->sc);
    }
    cout<<k;
}