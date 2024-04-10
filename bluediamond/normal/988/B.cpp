#include <iostream>
#include <algorithm>
#include <string>
///#include <set>
///#include <map>
///#include <vector>
///#include <cmath>
///#include <iomanip>
///#include <cstdio>

using namespace std;

const int N=100;
int n;
string v[N+5];

bool cmp(string a,string b){
    return a.size()<b.size();
}

bool is(string a,string caut){
    int l=a.size();
    for(int i=0;i+l-1<caut.size();i++){
        int st=i;
        int dr=i+l-1;
        int p=0;
        bool ok=1;
        for(int j=st;j<=dr;j++){
            if(a[p]!=caut[j]){
                ok=0;
                break;
            }
            p++;
        }
        if(ok==1)
            return 1;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1,cmp);
    for(int i=2;i<=n;i++){
        if(is(v[i-1],v[i])==0){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}
/**
**/